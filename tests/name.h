#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <string>

enum CallTransType
{
    TT_invalid,
    TT_newCall,
    TT_modifyCall,
    TT_releaseCall,
    TT_mergeCall,
    TT_requestConfRes,
    TT_addCall,
    TT_transfer,
    TT_confNew
};

class Name
{
public:
    Name() : i(0), b(TT_transfer)
    {
    }
    Name(int x, CallTransType y)
    {
        i = x;
        b = y;
    }

    void setB(CallTransType b_){
        b = b_;
    }

    void setI(int i_){
        i = i_;
    }

    int getB() const 
    {
        return b;
    }
    int getI() const
    {
        return i;
    }

private:
    int i;
    CallTransType b;
};
#endif
