
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "TriagePatient.h"
#define MAXCHARS 511
using namespace std;
namespace sdds {
	int nxttriangletcket = 1;
	TriagePatient::TriagePatient() :Patient(nxttriangletcket)
	{
		symptom = nullptr;
		nxttriangletcket++;
	}
	char TriagePatient::type() const
	{
		return 'T';
	}
	TriagePatient::~TriagePatient()
	{
		delete[] symptom;
		symptom = nullptr;
	}
	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr) << ',' << symptom;
		return ostr;
	}
	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		char cstr_symptoms[MAXCHARS + 1] = { '\0' };
		delete[] symptom;
		Patient::csvRead(istr);
		istr.ignore(2000, ',');
		istr.get(cstr_symptoms, MAXCHARS + 1, '\n');
		symptom = new char[strlen(cstr_symptoms) + 1];
		strncpy(symptom, cstr_symptoms, strlen(cstr_symptoms) + 1);
		istr.clear();
		nxttriangletcket = Patient::number() + 1;
		return istr;
	}
	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (Patient::fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr) << endl;
			ostr << "Symptoms: " << symptom << endl;
		}
		return ostr;
	}
	std::istream& TriagePatient::read(std::istream& istr)
	{
		char cstr_symptoms[MAXCHARS + 1] = { '\0' };
		if (Patient::fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] symptom;
			Patient::read(istr);
			cout << "Symptoms: ";
			istr.get(cstr_symptoms, MAXCHARS + 1, '\n');
			istr.clear();
			istr.ignore(2000, '\n');
			symptom = new char[strlen(cstr_symptoms) + 1];
			strcpy(symptom, cstr_symptoms);
		}
		return istr;
	}
}
