//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.

#ifndef SDDS_COVIDPATIENT_H
#define SDDS_COVIDPATIENT_H
#include "Patient.h"
namespace sdds
{
	class CovidPatient : public Patient
	{
	public:
		CovidPatient();
		char type()const;
		std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);

	};


}

#endif // !SDDS_COVIDPATIENT_H
