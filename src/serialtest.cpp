#include <iostream>
#include <string>
#include <sstream>
#include "serialtest.h"
using namespace std;

P2PCall::P2PCall(int zz)
{
	yy = zz;
}

// int P2PCall::getYY()
// {
// 	return yy;
// }

int P2PCall::getZZ()
{
	aa = 1;
	return aa;
}

McpttCall::McpttCall()
{
}
McpttCall::McpttCall(int yy)
{
	m_int = yy;
}

void McpttCall::setNameObj(Name naObj)
{
	m_na = naObj;
}

void McpttCall::setNamePtr(Name *obj)
{
	m_naPtr = obj;
}
int McpttCall::getValue()
{
	vector<Name *>::iterator it = m_Name.begin();
	while (it != m_Name.end())
	{
		Name *trans = *it;
		printf("Name obj I = %d, B = %d\n", trans->getI(), trans->getB());
		it++;
	}
	return m_int;
}

void McpttCall::addNameObj(Name *obj)
{
	m_Name.push_back(obj);
}
int McpttCall::getY()
{
	return getZZ() + 23;
}



