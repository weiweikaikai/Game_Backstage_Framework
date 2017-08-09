#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern "C" {

}

#include"server.h"




/*
 * @brief AsyncServer框架可选实现的的接口之一(父子)
*/
 extern "C" int  init_service(int isparent)
{
   g_proto_processor = new ProtoProcessor();

    if (!isparent) { //child
    
    
    }
   return 0;
}

/** 
 * @brief AsyncServer框架可选实现的接口之一(父子)
 **/
extern "C" int  fini_service(int isparent)
{
    delete g_proto_processor;

    if (!isparent) {
 
    
    }

    return 0;
}


/** 
 * @brief AsyncServer框架可选实现的接口之一(子)
 **/

extern "C" void proc_events()
{


}

/** 
 * @brief AsyncServer框架要求必须实现的接口之一(父子)
 **/

extern "C" int get_pkg_len(int fd, const void* avail_data, int avail_len, int isparent)
{
    if (isparent) {
     //   return g_proto_processor->get_pkg_len(fd, avail_data, avail_len, PROTO_FROM_CLIENT); 
    } else {
      //  return g_proto_processor->get_pkg_len(fd, avail_data, avail_len, PROTO_FROM_SERV); 
    }
    return 0;
}

/**
 ** @brief AsyncServer框架要求必须实现的接口之一(子) 
 **
 **/
extern "C" int  proc_pkg_from_client(void* data, int len, fdsession_t* fdsess)
{
     return g_proto_processor->proc_pkg_from_client(data, len, fdsess);
}


extern "C"int pkg_from_serv(int fd, void* data, int len)
{


}
