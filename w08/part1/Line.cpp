/*
	Name: Daryl Alex
	ID : 143691202
	Email : dalex4@myseneca.ca
	Date: 22-07-2021
*/
#include <iomanip>
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() :m_length(0) {
		//m_length=0;
	}
	Line::Line(const char* label, int length) : LblShape(label), m_length(length) {
		//m_length=length;
	}

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& os)const {
		if (m_length > 0 && label() != nullptr)
		{
			os << label() << endl;
			for (int i = 0; i < m_length; i++)	os << "=";
		}
	}
}