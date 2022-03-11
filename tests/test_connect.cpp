#include <sw/redis++/redis++.h>
#include <iostream>
#include <unistd.h>
#include "../src/redisTool.h"

using namespace sw::redis;
using namespace std;

int main()
{


    int cnt = 0;
    RedisTool redisTool("127.0.0.1", 6379, 3, MS(100), MS(100), MS(100));
    while (true)
    {

        string key = "key_" + to_string(cnt);
        string val = "val_" + to_string(cnt);
        redisTool.setString(key, val);
        cout << "set key : " << key << " val : " << val << endl;
        val = redisTool.getString(key);
        cout << "get key : " << key << " val : " << val << endl;
        cnt++;
        sleep(2);
    }

    return 0;
}