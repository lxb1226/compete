#ifndef NAME2_H
#define NAME2_H
#include <iostream>
#include <string>
#include "name.h"
using namespace std;

class Name2 : public Name
{
public:
	Name2() {}
	Name2(int x, CallTransType y) : Name(x, y) {}
	Name2(int x, CallTransType y, int i, int b) : Name(x, y), ii(i), bb(b){}
	~Name2() {}

	void setII(int i){
		ii = i;
	}

	void setBB(int b){
		bb = b;
	}

	int getII() const{
		return ii;
	}

	int getBB() const{
		return bb;
	}


private:
	int ii;
	int bb;
};
#endif
