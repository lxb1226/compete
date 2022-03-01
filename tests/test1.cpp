#include <iostream>
#include <string>
#include "include/redis_handler.h"
using namespace std;

int main()
{
    
    RedisHandler* rh = new RedisHandler();
    int ret;

    // 测试连接
    ret = rh->connect("127.0.0.1", 6379, "linesum");
    if (ret != M_REDIS_OK)
    {
    
        cout << "redis error: " << rh->getErrorMsg() << endl;
        return ret;
    }else{
        cout << "redis connect success!" << endl;
    }

    // 测试设置值
    ret = rh->setValue("key11", "value11");
    if (ret != M_REDIS_OK)
    {
    
        cout << "redis error: " << rh->getErrorMsg() << endl;
        return ret;
    }else{
        cout << "set value success!" << endl;
    }

    ret = rh->setValue("key22", "value22");
    if (ret != M_REDIS_OK)
    {
    
        cout << "redis error: " << rh->getErrorMsg() << endl;
        return ret;
    }else{
        cout << "set value success!" << endl;
    }

    // get测试
    string str;
    ret = rh->getValue("key11", str);
    if (ret != M_REDIS_OK)
    {
    
        cout << "redis error: " << rh->getErrorMsg() << endl;
        return ret;
    }
    else
        cout << "value : " << str << endl;

    //print测试
    ret = rh->printAll();
    if (ret != M_REDIS_OK)
    {
    
        cout << "redis error: " << rh->getErrorMsg() << endl;
        return ret;
    }else{
        cout << "printAll success!" << endl;
    }

    // del测试
    ret = rh->delKey("key11");
    if (ret != M_REDIS_OK)
    {
    
        cout << "redis error: " << rh->getErrorMsg() << endl;
        return ret;
    }else{
        cout << "redis del success!" << endl;
    }

    
    delete rh;

    return 0;
}