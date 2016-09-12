// vim: set expandtab tabstop=4 shiftwidth=4 fdm=marker:
// +----------------------------------------------------------------------+
// | Club Library.                                                        |
// +----------------------------------------------------------------------+
// | Copyright (c) 2005-2006 Tencent Inc. All Rights Reserved.            |
// +----------------------------------------------------------------------+
// | Authors: The Club Dev Team, ISRD, Tencent Inc.                       |
// |          fishchen <fishchen@tencent.com>                             |
// +----------------------------------------------------------------------+
// $Id$

/**
 * @version $Revision$
 * @author  $Author$
 * @date    $Date$
 * @brief   Clib Mysql.
 */
//#include "stdafx.h"
//#include "./../mysqlcsample/stdafx.h"
#include "clib_mysql.h"


/* {{{ clib_mysql::clib_mysql() */
/**
 * Initial clib_mysql class.
 *
 * @param   as_host     MYSQL server HOST/IP.
 * @param   ai_port     MYSQL server port.
 * @param   as_user     MYSQL server user name.
 * @param   as_pass     MYSQL server password.
 * @param   as_db       Database name.
 */
clib_mysql::clib_mysql( const char *as_host,
                        const int  ai_port,
                        const char *as_user,
                        const char *as_pass,
                        const char *as_db )
{
#ifdef WIN32
    _snprintf_s( ms_host, sizeof(ms_host), "%s", as_host );
	_snprintf_s(ms_user, sizeof(ms_user), "%s", as_user);
	_snprintf_s(ms_pass, sizeof(ms_pass), "%s", as_pass);
	_snprintf_s(ms_db, sizeof(ms_db), "%s", as_db);

#else
	snprintf(ms_host, sizeof(ms_host), "%s", as_host);
	snprintf(ms_user, sizeof(ms_user), "%s", as_user);
	snprintf(ms_pass, sizeof(ms_pass), "%s", as_pass);
	snprintf(ms_db, sizeof(ms_db), "%s", as_db);
#endif
    mi_port     = ai_port;
    mi_conn     = 0;
    mpst_result = NULL;

  
#ifndef WIN32
	memset( &mst_lock, 0, sizeof(mst_lock) );
    pthread_mutex_init( &mst_lock, NULL );
#endif
}
/* }}} */


/* {{{ clib_mysql::~clib_mysql() */
/**
 * Destory clib_mysql class.
 */
clib_mysql::~clib_mysql( void )
{
    this->free_result();
    this->db_close();
#ifndef WIN32
    pthread_mutex_destroy( &mst_lock );
#endif
}
/* }}} */


/* {{{ clib_mysql::db_connect() */
/**
 * Connect to MYSQL server.
 *
 * @return              0: succ, !=0: fail.
 */
int clib_mysql::db_connect()
{
    int     i_ret = 0;
    MYSQL   *pst_mysql = NULL;

#ifndef WIN32
    pthread_mutex_lock( &mst_lock );
#endif
    mysql_init( &mst_mysql );
    pst_mysql = mysql_real_connect( &mst_mysql,
                        ms_host,
                        ms_user,
                        ms_pass,
                        NULL,
                        mi_port,
                        NULL,
                        0 );
    if ( pst_mysql == NULL ) {
        mysql_close( &mst_mysql );
        mi_conn = 0;
        i_ret   = CLIB_MYSQL_ERR_CONN;
    } else {
        mi_conn = 1;
        i_ret   = CLIB_MYSQL_OK;
    } // if
#ifndef WIN32
    pthread_mutex_unlock( &mst_lock );
#endif
    return( i_ret );
}
/* }}} */


/* {{{ clib_mysql::db_close() */
/**
 * Close MYSQL connection.
 *
 * @return              0: succ, !=0: fail.
 */
int clib_mysql::db_close()
{
#ifndef WIN32
    pthread_mutex_lock( &mst_lock );
#endif
    if ( mi_conn != 0 ) mysql_close( &mst_mysql );
#ifndef WIN32
    pthread_mutex_unlock( &mst_lock );
#endif
    return( CLIB_MYSQL_OK );
}
/* }}} */


/* {{{ clib_mysql::set_db() */
/**
 * Select use database;
 *
 * @param   as_db       Database name.
 * @return              0: succ, !=0: fail.
 */
int clib_mysql::set_db( char *as_db )
{
    if ( as_db == NULL || strlen(as_db) <= 0 ) {
        return( CLIB_MYSQL_ERR_PARA );
    } // if

    // Checks whether the connection to the server is working.
    // If it has gone down, an automatic reconnection is attempted.
    if ( 0 != mysql_ping( &mst_mysql ) ) {
        return CLIB_MYSQL_ERR_CONN;
    }

    if ( mysql_select_db(&mst_mysql, as_db) != 0 ) {
        return( CLIB_MYSQL_ERR_SYST );
    } // if

    return( CLIB_MYSQL_OK );
}
/* }}} */


/* {{{ clib_mysql::real_query() */
/**
 * Query SQL.
 *
 * @note                Will store result, if it's a select statment.
 * @param   as_sql      SQL string.
 * @param   al_len      SQL string's length.
 * @return              0: succ, !=0: fail.
 */
int clib_mysql::real_query( const char *as_sql, const unsigned long al_len )
{
    int i_ret = 0;

    if ( as_sql == NULL ) {
        return( CLIB_MYSQL_ERR_PARA );
    } // if

    this->free_result();

    // Checks whether the connection to the server is working.
    // If it has gone down, an automatic reconnection is attempted.
    if ( 0 != mysql_ping( &mst_mysql ) ) {
        return CLIB_MYSQL_ERR_CONN;
    }

    i_ret = mysql_real_query( &mst_mysql, as_sql, al_len );
    if ( i_ret != 0 ) return( CLIB_MYSQL_ERR_QUER );

    mpst_result = mysql_store_result( &mst_mysql );
    if ( mpst_result == NULL && mysql_field_count(&mst_mysql) != 0 ) {
        return( CLIB_MYSQL_ERR_STOR );
    } else {
        return( CLIB_MYSQL_OK );
    } // if
}
/* }}} */


/* {{{ clib_mysql::query() */
/**
 * Query SQL.
 *
 * @note                Will store result, if it's a select statment.
 * @param   as_sql      SQL string.
 * @return              0: succ, !=0: fail.
 */
int clib_mysql::query( const char *as_sql )
{
    int i_ret = 0;

    if ( as_sql == NULL || strlen(as_sql) <= 0 ) {
        return( CLIB_MYSQL_ERR_PARA );
    } // if

    i_ret = this->real_query( as_sql, strlen(as_sql) );
    return( i_ret );
}
/* }}} */


/* {{{ clib_mysql::free_result() */
/**
 * Free result.
 *
 * @return              0: succ, !=0: fail.
 */
int clib_mysql::free_result()
{
    if ( mpst_result != NULL ) {
        mysql_free_result( mpst_result );
    } // if
    mpst_result = NULL;
    return( CLIB_MYSQL_OK );
}
/* }}} */


/* {{{ clib_mysql::fetch_row() */
/**
 * Fetch row.
 *
 * @retval              !=NULL: succ, ==NULL:fail.
 */
MYSQL_ROW clib_mysql::fetch_row()
{   
    if ( mpst_result != NULL ) {
        return( mysql_fetch_row( mpst_result ) );
    } else {
        return( NULL );
    } //if
}
/* }}} */


/* {{{ clib_mysql::num_rows() */
/**
 * Get number of rows.
 *
 * @retval              Result rows count.
 */
int clib_mysql::num_rows()
{
    return( mysql_num_rows(mpst_result) );
}
/* }}} */


/* {{{ clib_mysql::num_fields() */
/**
 * Get number of fields.
 *
 * @retval              Result fields count.
 */
int clib_mysql::num_fields()
{
    return( mysql_num_fields(mpst_result) );
}
/* }}} */

/* {{{ clib_mysql::affected_rows() */
/**
 * Get affected rows.
 *
 * @retval              Affected rows count.
 */
int clib_mysql::affected_rows()
{
    return( mysql_affected_rows(&mst_mysql) );
}
/* }}} */


/* {{{ clib_mysql::fetch_lengths() */
/**
 * Returns the lengths of the columns of the current row.
 *
 * @retval              Result rows count.
 */
unsigned long * clib_mysql::fetch_lengths()
{
    return( mysql_fetch_lengths(mpst_result) );
}
/* }}} */


/* {{{ clib_mysql::data_seek() */
/**
 * Seek data row(s).
 *
 * @return              0: succ, !=0: fail.
 */
int clib_mysql::data_seek( int ai_num )
{
    mysql_data_seek( mpst_result, ai_num );
    return( CLIB_MYSQL_OK );
}
/* }}} */


/* {{{ clib_mysql::get_errno() */
/**
 * Get MYSQL error code.
 *
 * @retval              Error code. 
 */
unsigned int clib_mysql::get_errno()
{
    return( mysql_errno( &mst_mysql ) );
}
/* }}} */


/* {{{ clib_mysql::get_error() */
/**
 * Get MYSQL error message.
 *
 * @retval              Error string. 
 */
const char *clib_mysql::get_error()
{
    return( mysql_error( &mst_mysql ) );
}
/* }}} */


/* {{{ clib_mysql::get_handle() */
/**
 * Get MYSQL handle.
 *
 * @retval  MYSQL *     MYSQL handle.
 */
MYSQL *clib_mysql::get_handle()
{
    return( &mst_mysql );
}
/* }}} */

/* {{{ clib_mysql::get_handle() */
/* set_character_set.
*
* @retval
* sean 20160912
*/
int clib_mysql::set_character_set(char *csname){
	return mysql_set_character_set(&mst_mysql, csname);
}

/* }}} */



