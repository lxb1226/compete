#pragma once
#include <iostream>
#include <vector>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>

using namespace std;
class Parent; // Forward declares
class Child;  // so my classes are in your order

class Family
{

  friend class boost::serialization::access;

public:
  Family() { ; }
  ~Family() { ; }

  vector<Parent *> m_members;

  Parent* ptr;
  //////////////////////////////////////////////////////////////////////
  template <class Archive>
  void serialize(Archive &ar, const unsigned int version)
  {
    ar.template register_type<Child>();
    ar &m_members;

    // ar.template register_type<Child>();
    ar &ptr;
  }
  //////////////////////////////////////////////////////////////////////
};

class Parent
{

  friend class boost::serialization::access;

public:
  Parent() : m_name("") { ; }
  Parent(string name) : m_name(name) { ; }
  ~Parent() { ; }

  virtual string GetName() { return m_name; }

private:
  string m_name;

  //////////////////////////////////////////////////////////////////////
  template <class Archive>
  void serialize(Archive &ar, const unsigned int version)
  {
    ar &m_name;
  }
  //////////////////////////////////////////////////////////////////////
};

class Child : public Parent
{

  friend class boost::serialization::access;

public:
  Child() : Parent(), m_age(0) { ; }
  Child(string name, int id) : Parent(name), m_age(id) { ; }
  ~Child() { ; }
  int m_age;

private:
  //////////////////////////////////////////////////////////////////////
  template <class Archive>
  void serialize(Archive &ar, const unsigned int version)
  {
    ar &boost::serialization::base_object<Parent>(*this);
    ar &m_age;
  }
  //////////////////////////////////////////////////////////////////////
};

int main()
{

  Family JohnsonFamily;
  for (int i = 0; i < 100; ++i)
  {
    Child *timmy = new Child("Timmy", i);
    JohnsonFamily.m_members.push_back(timmy);
  }

  Child* child_ptr = new Child("child_ptr", 100);
  JohnsonFamily.ptr = child_ptr;

  // serialize object into a std::string
  std::string serial_str;
  boost::iostreams::back_insert_device<std::string> inserter(serial_str);
  boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>> s(inserter);
  boost::archive::binary_oarchive oa(s);

  oa &JohnsonFamily;
  s.flush();

  // read object backout of standard string into new Family object
  boost::iostreams::basic_array_source<char> device(serial_str.data(), serial_str.size());
  boost::iostreams::stream<boost::iostreams::basic_array_source<char>> t(device);
  boost::archive::binary_iarchive ia(t);

  Family FosterFamily;
  ia &FosterFamily;

  for (auto &member : FosterFamily.m_members)
  {
    auto child = dynamic_cast<Child *>(member);
    // cout << "Derived type infered from serialized base pointer." << endl;
    cout << child->GetName() << " is " << child->m_age << endl;
  }
  
  auto ptr = dynamic_cast<Child*>(FosterFamily.ptr);
  cout << ptr->GetName() << "is " << ptr->m_age << endl;

  cin.get();
  return 0;
}