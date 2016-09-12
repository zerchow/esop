#gcc version
CC  = gcc
CXX = g++
GCCVER := $(shell $(CC) -dumpversion | awk -F. '{ print $$1"."$$2}' )

INC += -I../include/spp_incl/ -I../include  -I./
#LIB += -lsppasync -lasync_epoll -lcore
LIB += -L/usr/lib64/mysql  -lmysqlclient

#BUILD_DIR=../../build 
OBJ_DIR=./obj
LIB_DIR=.

LIB_NAME=spp_esop.so 

TARGET = $(LIB_DIR)/$(LIB_NAME)

OBJ_MSG = $(OBJ_DIR)/process_message.o 

OBJ_MSG = $(OBJ_DIR)/process_message.o 

OBJ_ApplicationController = $(OBJ_DIR)/ApplicationController.o 
OBJ_ControllerFactory = $(OBJ_DIR)/ControllerFactory.o 
OBJ_ControllerBase = $(OBJ_DIR)/ControllerBase.o 
OBJ_ProtocolData = $(OBJ_DIR)/ProtocolData.o 
OBJ_ProtocolHeader = $(OBJ_DIR)/ProtocolHeader.o 
OBJ_ApplicationModel = $(OBJ_DIR)/ApplicationModel.o 
OBJ_ModelBase = $(OBJ_DIR)/ModelBase.o 

OBJ_MYSQL = $(OBJ_DIR)/clib_mysql.o 
OBJ_LOG = $(OBJ_DIR)/clib_log.o 
OBJ = $(OBJ_DIR)/esop.o  \
	  $(OBJ_MSG) \
	  $(OBJ_ApplicationController) \
	  $(OBJ_ControllerFactory) \
	  $(OBJ_ControllerBase) \
	  $(OBJ_ProtocolData) \
	  $(OBJ_ProtocolHeader) \
	  $(OBJ_ApplicationModel) \
	  $(OBJ_ModelBase) \
	  $(OBJ_MYSQL) \
	  $(OBJ_LOG)

OBJ_EXT= .o
CXXSRC_EXT= .cpp
CSRC_EXT= .c

ifeq ($(ARCH),32)
	CFLAGS += -m32 -march=pentium4
endif
CFLAGS  += -g -fPIC -shared -Wall -O2 -pipe -fno-ident -MMD -D_GNU_SOURCE -D_REENTRANT
CXXFLAGS+=$(CFLAGS)


$(OBJ_DIR)/%$(OBJ_EXT): %$(CXXSRC_EXT)
	@echo
	@echo "Compiling $< ==> $@..."
	@-mkdir -p $(OBJ_DIR)
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%$(OBJ_EXT): %$(CSRC_EXT)
	@echo
	@echo "Compiling $< ==> $@..."
	@-mkdir -p $(OBJ_DIR)
	$(CXX) $(INC) $(CFLAGS) -c $< -o $@


all:$(TARGET)

$(TARGET) : $(OBJ)
	@echo
	@echo "Building $^ ==> $@..."
	@-mkdir -p $(LIB_DIR)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIB)  -ljson_linux-gcc-4.4.7_libmt 
	install *.so ../../bin

clean:
	@echo
	@echo "Cleaning..." 
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)	

all32:
	make -e ARCH=32
