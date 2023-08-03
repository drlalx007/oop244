//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		m_symptoms = nullptr;
		nextTriageTicket++;
	}
	char TriagePatient::type()const
	{
		return 'T';
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
	}

	std::ostream& TriagePatient::write(std::ostream& ostr)const
	{
		if (fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr) << endl;
			ostr << "Symptoms: " << m_symptoms << endl;

		}
		return ostr;
	}

	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		istr.ignore();
		delete[] m_symptoms;
		m_symptoms = getcstr(nullptr, istr);
		nextTriageTicket = Patient::number() + 1;
		return istr;
	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const
	{
		Patient::csvWrite(ostr);
		return ostr << "," << m_symptoms;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] m_symptoms;
			Patient::read(istr);
			m_symptoms = getcstr("Symptoms: ");
		}
		return istr;
	}

}