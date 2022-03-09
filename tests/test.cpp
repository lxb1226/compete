#include <iostream>
#include "serialtest.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/base_object.hpp>
 
using namespace std;

namespace boost
{
    namespace serialization
    {

        template <class Archive>
        void serialize(Archive &ar, BaseCall &baseCall, const unsigned int version)
        {
        }

        template <class Archive>
        void save(Archive &ar,const P2PCall &p2pcall, const unsigned int version)
        {
            ar &base_object<BaseCall>(p2pcall);

            ar &p2pcall.a1;
            ar &p2pcall.a;
            ar &p2pcall.getYY();
            ar &p2pcall.getAA();
        }

        template <class Archive>
        void load(Archive &ar, P2PCall &p2pcall, const unsigned int version)
        {
            ar &base_object<BaseCall>(p2pcall);
            ar &p2pcall.a1;
            ar &p2pcall.a;
            int tmp;
            ar &tmp;
            p2pcall.setYY(tmp);
            ar &tmp;
            p2pcall.setAA(tmp);
        }

        template <class Archive>
        void save(Archive &ar, const McpttCall &p, const unsigned int version)
        {
            ar &base_object<P2PCall>(p);
            // public
            ar &p.a2;
            ar &p.a;
            // private
            ar &p.getMBool();
            ar &p.getMChar();
            ar &p.getMInt();
            ar &p.getMDouble();
            ar &p.getMStr();

            // TODO:如何处理vector<Name*> boost是否提供支持?
            ar.template register_type<Name>();
            ar &p.getVecNamePtr();
            ar &p.getName();
            ar.template register_type<Name>();
            ar &p.getNamePtr();

        }

        template <class Archive>
        void load(Archive &ar, McpttCall &p, const unsigned int version)
        {
            ar &base_object<P2PCall>(p);
            // public
            ar &p.a2;
            ar &p.a;
            // private
            bool t_bool;
            char t_char;
            int t_int;
            double t_double;
            string t_str;
            ar &t_bool;
            p.setMBool(t_bool);
            ar &t_char;
            p.setMChar(t_char);
            ar &t_int;
            p.setMInt(t_int);
            ar &t_double;
            p.setMDouble(t_double);
            ar &t_str;
            p.setMStr(t_str);
            // ar &p.m_bool;
            // ar &p.m_char;
            // ar &p.m_int;
            // ar &p.m_double;
            // ar &p.m_str;

            // TODO:如何处理vector<Name*> boost是否提供支持?
            Name t_na;
            Name *t_naPtr;

            vector<Name*> t_Name;
            ar &t_Name;
            p.setVecNamePtr(t_Name);
            ar &t_na;
            p.setNameObj(t_na);
            ar &t_naPtr;
            p.setNamePtr(t_naPtr);

        }

        template <class Archive>
        void save(Archive &ar, const Name &name, const unsigned int version)
        {
            ar &name.getI();
            ar &name.getB();
        }

        template <class Archive>
        void load(Archive &ar, Name &name, const unsigned int version)
        {
            int i = 0;
            CallTransType b;
            ar &i;
            ar &b;
            name.setI(i);
            name.setB(b);
        }

        template <class Archive>
        void save(Archive &ar, const Name2 &name, const unsigned int version)
        {
            ar &base_object<Name>(name);
            ar &name.getII();
            ar &name.getBB();
        }

        template <class Archive>
        void load(Archive &ar, Name2 &name, const unsigned int version)
        {
            int i = 0, b = 0;
            ar & i;
            ar & b;
            name.setII(i);
            name.setBB(b);
        }

    }
}

BOOST_SERIALIZATION_SPLIT_FREE(P2PCall);
BOOST_SERIALIZATION_SPLIT_FREE(McpttCall);
BOOST_SERIALIZATION_SPLIT_FREE(Name);
BOOST_SERIALIZATION_SPLIT_FREE(Name2);



int main()
{
    
    McpttCall *test = new McpttCall(true, 'm', 50, 17.89, "fuzhijie");
    for (int i = 0; i < 100; i++)
    {
        Name2 *na = new Name2(i, TT_releaseCall);
        test->addNameObj(na);
    }

    Name *na1 = new Name(101, TT_newCall);
    test->addNameObj(na1);

    long long begin, end;

    Name *obj = new Name(102, TT_newCall);
    test->setNamePtr(obj);

    // 可以实现序列化，但是反序列化有问题
    std::stringstream stream;
    {

        boost::archive::text_oarchive ar(stream);
        ar << test;

        std::cout << "Size: " << stream.str().size() << "\n";
        std::cout << "str : " << stream.str() << "\n";
    }

    {
        // stream.clear();
        // stringstream s;
        McpttCall newTest;
        boost::archive::text_iarchive ir(stream);
        ir >> newTest;
        
    }
}