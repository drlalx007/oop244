//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :22/07/2021.

#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	Time& Time::setToNow()
	{
		m_minutes = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_minutes = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr << setw(2) << setfill('0') << right << m_minutes / 60 << ":" << setw(2) << setfill('0') << right << m_minutes % 60;
		ostr.fill(' ');
		ostr.unsetf(ios::right);
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hour = 0;
		int min = 0;
		istr >> hour;
		if (hour < 0) istr.setstate(ios::failbit);
		if (istr.get() != ':') istr.setstate(ios::failbit);
		istr >> min;
		if (min < 0) istr.setstate(ios::failbit);
		if (istr) {
			m_minutes = (unsigned)min + hour * 60;
		}
		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		while (m_minutes < D.m_minutes) {
			m_minutes += 1440;
		}
		m_minutes = m_minutes - D.m_minutes;
		return *this;

	}

	Time Time::operator-(const Time& D) const
	{
		Time ret = *this;
		ret -= D;
		return ret;
	}

	Time& Time::operator+=(const Time& D)
	{
		m_minutes += D.m_minutes;
		return *this;
	}

	Time Time::operator+(const Time& D) const
	{
		Time ret = *this;
		ret += D;
		return ret;
	}

	Time& Time::operator=(unsigned int val)
	{
		m_minutes = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val)
	{
		m_minutes *= val;
		return *this;
	}

	Time& Time::operator/=(unsigned int val)
	{
		m_minutes /= val;
		return *this;
	}

	Time Time::operator*(unsigned int val) const
	{
		return Time(m_minutes * val);
	}

	Time Time::operator/(unsigned int val) const
	{
		return Time(m_minutes / val);
	}

	Time::operator unsigned int() const
	{
		return m_minutes;
	}

	Time::operator int() const
	{
		return int(m_minutes);
	}


	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}


}