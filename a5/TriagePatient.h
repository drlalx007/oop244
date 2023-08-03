//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.

#ifndef SDDS_TRIAGEPATIENT
#define SDDS_TRIAGEPATIENT
#include "Patient.h"
namespace sdds
{
	class TriagePatient :public Patient
	{
		char* m_symptoms = nullptr;
	public:
		char type()const;
		TriagePatient();
		~TriagePatient();
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};

}
#endif // !SDDS_TRIAGEPATIENT
