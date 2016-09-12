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
 * @brief   Define value.
 */


#ifndef _CLIB_MYSQL_H_
#define _CLIB_MYSQL_H_

#include <stdio.h>
#include <string.h>
#ifdef WIN32
#include "mysql.h"
#include "mysqld_error.h"
#else
#include <pthread.h>
#include "/usr/include/mysql/mysql.h"
#include "/usr/include/mysql/mysqld_error.h"
#endif


// version
#define CLIB_MYSQL_VERSTR    "0.1.2"
#define CLIB_MYSQL_VERNUM    102

// system define
#define CLIB_MYSQL_SLEN_SHOR 16
#define CLIB_MYSQL_SLEN_NORM 64
#define CLIB_MYSQL_SLEN_LONG 256

// return
#define CLIB_MYSQL_OK        0
#define CLIB_MYSQL_ERR_PARA  800
#define CLIB_MYSQL_ERR_CONN  801
#define CLIB_MYSQL_ERR_QUER  802
#define CLIB_MYSQL_ERR_STOR  803
#define CLIB_MYSQL_ERR_SYST  899
extern "C" {

class clib_mysql
{
private:
    char ms_erro[CLIB_MYSQL_SLEN_LONG];
    char ms_host[CLIB_MYSQL_SLEN_NORM];
    int  mi_port;
    char ms_user[CLIB_MYSQL_SLEN_NORM];
    char ms_pass[CLIB_MYSQL_SLEN_NORM];
    char ms_db[CLIB_MYSQL_SLEN_NORM];

#ifndef WIN32
    pthread_mutex_t mst_lock;
#endif
    int             mi_conn;
    MYSQL           mst_mysql;
    MYSQL_RES       *mpst_result;
    
public:
	/**
	* Initial clib_mysql class.
	* @param   as_host     MYSQL server HOST/IP.
    * @param   ai_port     MYSQL server port.
    * @param   as_user     MYSQL server user name.
    * @param   as_pass     MYSQL server password.
    * @param   as_db       Database name.
	*/
	static clib_mysql *get_instance(const char *as_host,
		const int  ai_port,
		const char *as_user,
		const char *as_pass,
		const char *as_db = NULL){
#ifndef WIN32
		static __thread clib_mysql* m_myclass = 0;
#else
		static  clib_mysql* m_myclass = 0;
#endif
		if (!m_myclass){
			m_myclass = new clib_mysql(as_host,
									ai_port,
									as_user,
									as_pass,
									as_db);
		}
		return m_myclass;
	}
	/**
	* destory clib_mysql class.
	* @param   as_host     MYSQL server HOST/IP.
	* @param   ai_port     MYSQL server port.
	* @param   as_user     MYSQL server user name.
	* @param   as_pass     MYSQL server password.
	* @param   as_db       Database name.
	*/
	static void destory_instance(){
		clib_mysql* m_myclass = get_instance("127.0.0.1",3366,"","");
		if (m_myclass != NULL){
			delete m_myclass;
			m_myclass = NULL;
		}

	}
    /**
     * Destory clib_mysql class.
     */
    ~clib_mysql( void );


    /**
     * Connect to MYSQL server.
     *
     * @return              0: succ, !=0: fail.
     */
    int db_connect();
    
    
    /**
     * Close MYSQL connection.
     *
     * @return              0: succ, !=0: fail.
     */
    int db_close();
    
    
    /**
     * Select use database;
     *
     * @param   as_db       Database name.
     * @return              0: succ, !=0: fail.
     */
    int set_db( char *as_db );


    /**
     * Query SQL.
     *
     * @note                Will store result, if it's a select statment.
     * @param   as_sql      SQL string.
     * @param   al_len      SQL string's length.
     * @return              0: succ, !=0: fail.
     */
    int real_query( const char *as_sql, const unsigned long al_len );

    
    /**
     * Query SQL.
     *
     * @note                Will store result, if it's a select statment.
     * @param   as_sql      SQL string.
     * @return              0: succ, !=0: fail.
     */
    int query( const char *as_sql );


    /**
     * Free result.
     *
     * @return              0: succ, !=0: fail.
     */
    int free_result();


    /**
     * Fetch row.
     *
     * @retval              !=NULL: succ, ==NULL:fail.
     */
    MYSQL_ROW fetch_row();


    /**
     * Get number of rows.
     *
     * @retval              Result rows count.
     */
    int num_rows();

    /**
     * Get number of cols（fields） in a row.
     *
     * @retval              Result fields count.
     */
    int num_fields();

    /**
     * Get affected rows.
     *
     * @retval              Affected rows count.
     */
    int affected_rows();


    /**
     * Returns the lengths of the columns of the current row.
     *
     * @retval              Result rows count.
     */
    unsigned long * fetch_lengths();


    /**
     * Seek data row(s).
     *
     * @return              0: succ, !=0: fail.
     */
    int data_seek( int ai_num );


    /**
     * Get MYSQL error code.
     *
     * @retval              Error code.
     */
    unsigned int get_errno();


    /**
     * Get MYSQL error message.
     *
     * @retval              Error string.
     */
    const char * get_error();


    /**
     * Get MYSQL handle.
     *
     * @retval  MYSQL *     MYSQL handle.
     */
    MYSQL * get_handle();

	/**
	* set_character_set.
	*
	* @retval
	* sean 20160912 
	*/
	int set_character_set(char *csname);

private:
	/**
	* Initial clib_mysql class.
	*
	* @param   as_host     MYSQL server HOST/IP.
	* @param   ai_port     MYSQL server port.
	* @param   as_user     MYSQL server user name.
	* @param   as_pass     MYSQL server password.
	* @param   as_db       Database name.
	*/
	clib_mysql(const char *as_host,
		const int  ai_port,
		const char *as_user,
		const char *as_pass,
		const char *as_db = NULL);
	clib_mysql();
	clib_mysql(const clib_mysql&);
	clib_mysql& operator=(const clib_mysql&);

};

}

#endif


