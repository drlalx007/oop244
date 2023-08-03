#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>
namespace sdds {
	class Mark {
		int m_score;
		int m_valid;
		void setInvalid();
		void setEmpty();
		void setValid();
		bool isValid(int value);
		void correctContent();
	public:
		Mark();
		Mark(int mark);
		operator bool()const;
		operator int() const;
		operator double()const;
		operator char()const;
		bool operator~() const;
		Mark& operator=(int value);
		Mark& operator+=(int value);
		double getMark() const;
	};
	double operator+=(int& value, const Mark& RightOperand);
}
#endif // SDDS_MARK_H_