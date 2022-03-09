#include <iostream>
#include "./src/RedisTools.h"
#include "./src/serialtest.h"
#include <unistd.h>

using namespace std;
using namespace XY;


std::ostream &operator<<(std::ostream &os, const Name &name)
{
    return os << "name.i : " << name.getI() << " "
              << "name.b : " << name.getB() << " ";
}

std::ostream &operator<<(std::ostream &os, const Name2 &name2)
{
    return os << "name2.i : " << name2.getI() << " name2.b : " << name2.getB() << " name2.ii : " << name2.getII() << " name2.bb : " << name2.getBB() << " ";
}

std::ostream &operator<<(std::ostream &os, const P2PCall &p2pCall)
{
    return os << "p2pCall.a1 : " << p2pCall.a1 << " p2pCall.a : " << p2pCall.a << " p2pCall.yy : " << p2pCall.getYY() << " p2pCall.aa : " << p2pCall.getAA() << " ";
}

std::ostream &operator<<(std::ostream &os, const McpttCall &call)
{
    os << "call.a2 : " << call.a2 << " call.a : " << call.a << " call.m_bool : " << call.getMBool() << " call.m_char : " << call.getMChar()
       << " call.m_int : " << call.getMInt() << " call.m_double : " << call.getMDouble() << " call.m_str : " << call.getMStr() << endl;
    os << "call.m_Name : " << call.getVecNamePtr().size() << endl;
    for (auto &name : call.getVecNamePtr())
    {
        cout << *name << endl;
    }
    os << "call.m_na : " << call.getName() << " call.m_naptr : " << *call.getNamePtr() << endl;
    return os;
}



McpttCall &constructData()
{
  McpttCall *call = new McpttCall(1, 1, true, 'm', 50, 17.89, "fuzhijie");
  for (int i = 0; i < 100; i++)
  {
    Name2 *na = new Name2(i, TT_releaseCall);
    call->addNameObj(na);
  }

  Name *na1 = new Name(101, TT_newCall);
  call->addNameObj(na1);

  long long begin, end;

  Name *obj = new Name(102, TT_newCall);
  call->setNamePtr(obj);

  return *call;
}

int main()
{
  RedisTool redis;
  string prefix = "McpttCall";
  Serialization<McpttCall> seriaTool;
  int cnt = 0;

  while (1)
  {
    string name = prefix + "_" + to_string(cnt);
    McpttCall call = constructData();
    std::cout << call << endl;
    stringstream stream;
    // 序列化
    seriaTool.serialize(call, stream);
    cout << stream.str() << endl;
    int ret = redis.setString(name, stream.str());
    if (ret < 0)
    {
      sleep(5);
      continue;
    }

    std::string result = redis.getString(name);
    // 反序列化
    stream.str(result);
    McpttCall newCall = seriaTool.deserialize(stream);

    std::cout << "deserialize : " << endl;
    std::cout << newCall << endl;
    cnt++;
    // sleep(5);
  }

  return 0;
}
