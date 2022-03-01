#include <cereal/archives/binary.hpp>
#include <sw/redis++/redis++.h>
#include <fstream>
#include <sstream>

using namespace sw::redis;
using namespace std;

class BaseTest{
  int i;
};

class Test:public BaseTest{
  std::string s;
  std::vector<int> v;
  int buffLen;
  // char *buff;
};

class SomeData
{
  public:
    SomeData() = default;
    int a;
    int b;

  private:
    friend class cereal::access;

    // cereal supports class versioning although it is considered
    // optional in cereal
    template <class Archive>
    void save( Archive & ar, std::uint32_t const version ) const
    {
      ar( a, b ); // operator() is the preferred way of interfacing the archive
    }

    template <class Archive>
    void load( Archive & ar, std::uint32_t const version )
    {
      ar( a, b );
    }

    // note the lack of explicitly informing cereal to use a split member load/save
};

CEREAL_CLASS_VERSION(SomeData, 1);

struct MyType
{
  int x;
  double y;
  vector<int> vs;
  string str;
  SomeData s;

  template <class Archive>
  void serialize( Archive & ar, std::uint32_t const version )
  {
    ar( x, y, vs, str);

    ar( s );
  }
};

int main()
{
  // std::ofstream os("out.bin", std::ios::binary);
  
  auto redis = Redis("tcp://127.0.0.1:6379");
  {
    std::stringstream ss; // any stream can be used
    cereal::BinaryOutputArchive ar(ss);
    
    MyType m;
    m.x = 1;
    m.y = 2;
    m.s.a = 1;
    m.s.b = 2;
    m.str = "该功";
    m.vs = vector<int>{1, 2, 3, 4};

    // Write the data to the archive
    ar(m);
    cout << ss.str() << endl;
    redis.set("key", ss.str());
  }

  {
    std::stringstream ss; // any stream can be used
    ss.str("");
    auto str = redis.get("key");
    ss << *str;
    cereal::BinaryInputArchive iarchive(ss); // Create an input archive

    MyType m;
    iarchive(m);
    cout << "m.x : " << m.x << "m.y : " << m.y << endl;
    cout << "m.s.a : " << m.s.a << "m.s.b : " << m.s.b << endl;
    cout << "m.str : " << m.str << endl;
    for(int i = 0; i < m.vs.size(); ++i){
      cout << m.vs[i] << endl;
    }

  }
  
  return 0;
}
