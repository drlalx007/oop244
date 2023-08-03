/*
	Name: Daryl Alex
	ID : 143691202
	Email : dalex4@myseneca.ca
	Date: 22-07-2021
*/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include<iostream>
namespace sdds {
	class Shape
	{
	public:
		virtual void draw(std::ostream&) const = 0;
		virtual void getSpecs(std::istream&) = 0;
		virtual ~Shape() {}

	};
	std::ostream& operator<< (std::ostream& os, const Shape& S);
	std::istream& operator>> (std::istream& is, Shape& S);
}
#endif //SDDS_SHAPE_H_