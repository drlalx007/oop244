
#include "CovidPatient.h"
using namespace std;
namespace sdds {
	int nxtcovidtickt = 1;

	CovidPatient::CovidPatient() : Patient(nxtcovidtickt)
	{
		nxtcovidtickt++;
	}
	char CovidPatient::type() const
	{
		return 'C';
	}
	std::istream& CovidPatient::csvRead(std::istream& istr) {
		Patient::csvRead(istr);
		nxtcovidtickt = number() + 1;
		istr.ignore(2000, '\n');
		return istr;
	}
	std::ostream& CovidPatient::write(std::ostream& ostr) const {
		if (fileIO() == true)
		{
			Patient::csvWrite(ostr);
		}
		else
		{
			ostr << "COVID TEST" << endl;
			Patient::write(ostr);
			ostr << endl;
		}
		return ostr;
	}
	std::istream& CovidPatient::read(std::istream& istr)
	{
		if (fileIO() == true) {
			CovidPatient::csvRead(istr);
		}
		else
		{
			Patient::read(istr);
		}return istr;
	}
}