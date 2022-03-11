#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/serialization.hpp>
#include <iostream>
#include <sstream>
#include <fstream>

using boost::serialization::make_binary_object;

enum class Example : uint8_t
{
    A = 1,
    B = 2,
};

class Test
{
public:
    std::string s;
    int buffLen;
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &s;
        ar &buffLen;
    }
};

void save()
{
    std::ofstream f("data.dat", std::ofstream::binary);
    boost::archive::binary_oarchive ar(f);

    // auto data = Example::A;
    Test test;
    test.s = "1234";
    test.buffLen = 12;
    ar << make_binary_object(&test, sizeof(test));
    // ar << test;
}

void load()
{
    std::ifstream f("data.dat", std::ifstream::binary);
    boost::archive::binary_iarchive ir(f, boost::archive::no_header);
    Test test1;
    ir >> test1;
    std::cout << test1.s << " " << test1.buffLen << std::endl;
}

int main()
{
    save();
    load();
}