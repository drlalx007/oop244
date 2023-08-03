#ifndef SDDS_TRIAGE_H
#define SDDS_TRIAGE_H
#include <iostream>
#include "IOAble.h"
#include "CovidPatient.h"
namespace sdds
{
	class TriagePatient :public Patient {
		char* symptom;
	public:
		TriagePatient();
		~TriagePatient();
		char type()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	}
	;
}
#endif // !SDDS_
