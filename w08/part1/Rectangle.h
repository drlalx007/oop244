/*
	Name: Daryl Alex
	ID : 143691202
	Email : dalex4@myseneca.ca
	Date: 22-07-2021
*/
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include"LblShape.h"
namespace sdds {
	class Rectangle : public LblShape {
		int m_width = 0, m_height = 0;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream&);
		void draw(std::ostream&)const;
	};
}
#endif //SDDS_RECTANGLE_H_