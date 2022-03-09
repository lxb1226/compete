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
#include <boost/serialization/export.hpp>

using namespace std;


namespace boost
{
    namespace serialization
    {

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
            cout << "save name2" << endl;
        }

        template <class Archive>
        void load(Archive &ar, Name2 &name, const unsigned int version)
        {
            int i = 0, b = 0;
            ar &base_object<Name>(name);
            ar &i;
            ar &b;
            cout << "load name2. i = " << i << " b = " << b << endl;
            name.setII(i);
            name.setBB(b);
        }

        template <class Archive>
        void serialize(Archive &ar, BaseCall &baseCall, const unsigned int version)
        {
        }

        template <class Archive>
        void save(Archive &ar, const P2PCall &p2pcall, const unsigned int version)
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

            vector<Name *> t_Name;
            ar.template register_type<Name>();
            ar &t_Name;
            p.setVecNamePtr(t_Name);
            ar &t_na;
            p.setNameObj(t_na);
            ar.template register_type<Name>();
            ar &t_naPtr;
            p.setNamePtr(t_naPtr);
        }
    }
}

BOOST_SERIALIZATION_SPLIT_FREE(P2PCall);
BOOST_SERIALIZATION_SPLIT_FREE(McpttCall);
BOOST_SERIALIZATION_SPLIT_FREE(Name);
BOOST_SERIALIZATION_SPLIT_FREE(Name2);

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

template<class T>
void process(T* t)
{
    stringstream stream;
    {
        boost::archive::binary_oarchive ar(stream);
        cout << *t << endl;
        ar &*t;
        cout << stream.str() << endl;
    }
    {
        boost::archive::binary_iarchive ir(stream);
        T newT;
        ir &newT;
        cout << newT << endl;
    }
}

void test_McpttCall()
{
    McpttCall *call = new McpttCall(true, 'm', 50, 17.89, "fuzhijie");
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
    process(call);
}

void test_P2PCall()
{
    P2PCall *call = new P2PCall(1, 2, 3, 4);
    
    process(call);
}

void test_name2()
{
    Name2 *name2 = new Name2(1, TT_mergeCall, 3, 4);
    stringstream stream;
    {
        boost::archive::text_oarchive ar(stream);
        cout << *name2 << endl;
        ar &*name2;
    }

    {
        boost::archive::text_iarchive ir(stream);
        Name2 new_name2;
        ir &new_name2;
        cout << new_name2 << endl;
    }
}

void test_name()
{
    Name *name = new Name(1, TT_mergeCall);
    stringstream stream;
    {
        boost::archive::text_oarchive ar(stream);
        cout << *name << endl;
        ar &*name;
    }

    {
        boost::archive::text_iarchive ir(stream);
        Name new_name;
        ir &new_name;
        cout << new_name << endl;
    }
}

int main()
{
    test_name();
    test_name2();
    test_P2PCall();
    test_McpttCall();
    return 0;
}
