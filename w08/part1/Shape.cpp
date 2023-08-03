/*
	Name: Darytl Alex
	ID : 143691202
	Email : dalex4@myseneca.ca
	Date: 22-07-2021
*/
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Shape& S)
	{
		S.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& S)
	{
		S.getSpecs(is);
		return is;
	}
}