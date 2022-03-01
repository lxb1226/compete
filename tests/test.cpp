#include <iostream>
#include "hiredis/hiredis.h"
 
using namespace std;
 
int main()
{
    redisContext *pContext = redisConnect("127.0.0.1",6379); //建立连接
    if(pContext->err)
    {
        redisFree(pContext);
        cout << "connect to redisServer fail" << endl;
        return -1;
    }
    cout << "connect to redisServer success" << endl;
    //执行命令
    redisReply *pReply = (redisReply*)redisCommand(pContext,"set main helloWorld");
    string name = "name";
    pReply = (redisReply*)redisCommand(pContext,"set %s xiaoluo",name.c_str());
    cout << pReply->str << endl;
 
    pReply = (redisReply*)redisCommand(pContext,"get %s",name.c_str());
    cout << pReply->str << endl;
    //释放连接
    freeReplyObject(pReply);
    redisFree(pContext);
    return 0;
}