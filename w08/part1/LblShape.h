/*
	Name: Daryl Alex
	ID : 143691202
	Email : dalex4@myseneca.ca
	Date: 22-07-2021
*/
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
namespace sdds {
	class LblShape: public Shape
	{
		char* m_label = nullptr;
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape&)=delete;
		void operator=(const LblShape&) = delete;
		void getSpecs(std::istream& is);
		};
}
#endif //SDDS_LBLSHAPE_H_