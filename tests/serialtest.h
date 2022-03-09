#ifndef SERIALTEST_H
#define SERIALTEST_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "name.h"
#include "name2.h"

using namespace std;

class BaseCall
{
public:
    BaseCall() {}
    virtual ~BaseCall() {}
    virtual int getY() = 0;
};

class P2PCall : public BaseCall
{
public:
    int a1;
    int a;
    P2PCall(){};
    P2PCall(int x);
    P2PCall(int a1_, int a_, int yy_, int aa_):a1(a1_), a(a_), yy(yy_), aa(aa_){}
    int getZZ();
    virtual int getY(){
        return yy;
    };

    // 添加get set函数
    void setYY(int y) { yy = y; }
    void setAA(int a) { aa = a; }
    int getYY() const { return yy; }
    int getAA() const{ return aa; }

private:
    int yy;
    int aa;
};

class McpttCall : public P2PCall
{
public:
    int a2;
    int a;
    McpttCall();
    McpttCall(int x);
    McpttCall(bool b, char ch, int i, double d, string str);
    int getValue();
    void setNameObj(Name naObj);

    void setNamePtr(Name *obj);
    void addNameObj(Name *obj);

    virtual int getY();

    void setMBool(bool _m_bool) {
        m_bool = _m_bool;
    }

    bool getMBool() const{
        return m_bool;
    }

    void setMChar(char _m_char) {
        m_char = _m_char;
    }

    char getMChar() const{
        return m_char;
    }

    void setMInt(int _m_int) {
        m_int = _m_int;
    }

    int getMInt() const {
        return m_int;
    }

    void setMDouble(double _m_double) {
        m_double = _m_double;
    }

    double getMDouble() const{
        return m_double;
    }

    void setMStr(string _m_str) {
        m_str = _m_str;
    }

    string getMStr() const{
        return m_str;
    }

    Name getName() const{
        return m_na;
    }

    Name* getNamePtr() const{
        return m_naPtr;
    }

    void setVecNamePtr(vector<Name*> _m_Name) {
        m_Name = _m_Name;
    }

    vector<Name*> getVecNamePtr() const{
        return m_Name;
    }

private:
    bool m_bool;
    char m_char;
    int m_int;
    double m_double;
    string m_str;
    vector<Name *> m_Name;

    Name m_na;
    Name *m_naPtr;
};

#endif
