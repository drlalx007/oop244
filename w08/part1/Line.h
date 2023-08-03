#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include"LblShape.h"
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream&);
		void draw(std::ostream&)const;
	};
}
#endif //SDDS_LINE_H_