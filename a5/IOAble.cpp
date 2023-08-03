//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.

#include<iostream>
#include "IOAble.h"
using namespace std;
namespace sdds
{
	IOAble::~IOAble()
	{

	}
	ostream& operator<<(ostream& ostr, const IOAble& IO)
	{
		return IO.write(ostr);
	}
	istream& operator>>(istream& istr, IOAble& IO)
	{
		return IO.read(istr);
	}
}