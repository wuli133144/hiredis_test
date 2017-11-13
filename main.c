#include <stdio.h>  
#include "hiredis-master/hiredis.h"
  
  int main()  
  {  
      redisContext* conn = redisConnect("127.0.0.1",6379);  
      if(conn->err)   printf("connection error:%s\n",conn->errstr);  
            
      redisReply* reply = redisCommand(conn,"set foo 1234");  
      freeReplyObject(reply);  
                      
      reply = redisCommand(conn,"get foo");  
                            
      printf("%s\n",reply->str);  
      freeReplyObject(reply);  
                                      
      redisFree(conn);  
                                            
      return 0;  
                                                  
}
