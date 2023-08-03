//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.

#include<iostream>
#include "CovidPatient.h"
using namespace std;
namespace sdds
{
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() :Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}

	char CovidPatient::type()const
	{
		return 'C';
	}

	std::istream& CovidPatient::read(std::istream& istr)
	{
		return fileIO() ? csvRead(istr) : Patient::read(istr);
	}

	std::ostream& CovidPatient::write(std::ostream& ostr)const
	{
		if (fileIO())
		{
			Patient::csvWrite(ostr);
		}
		else
		{
			ostr << "COVID TEST" << endl;
			Patient::write(ostr) << endl;
		}
		return ostr;
	}

	std::istream& CovidPatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;
		istr.ignore(1000, '\n');
		return istr;
	}

}