//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :12/07/2021.



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
		ostr.fill('0');
		ostr.width(2);
		ostr << retHours() << ":";

		ostr.fill('0');
		ostr.width(2);
		ostr << retMinutes();
		return ostr;
	}
	std::istream& Time::read(std::istream& istr)
	{
		int hrs = 0;
		int min = 0;
		char A = '\0';

		istr >> hrs;
		if (hrs < 0)
		{
			istr.setstate(ios::failbit);
		}
		else m_minutes = hrs * 60;

		istr.get(A);
		if (A != ':')
		{
			istr.setstate(ios::failbit);
		}

		istr >> min;
		if (min < 0)
		{
			istr.setstate(ios::failbit);
		}
		else m_minutes += min;

		return istr;
	}
	Time& Time::operator-=(const Time& D)
	{
		bool valid = true;

		if (m_minutes < D.m_minutes)
		{
			int A = 1;
			while (valid)
			{
				if ((m_minutes + (60 * 24 * A) < D.m_minutes))	A++;
				else valid = false;
			}

			m_minutes += (60 * 24 * A);
			m_minutes -= D.m_minutes;
		}
		else
		{
			m_minutes -= D.m_minutes;
		}
		return *this;
	}
	Time Time::operator-(const Time& D) const
	{
		bool check = true;
		Time temp;
		if (m_minutes < D.m_minutes)
		{
			int x = 1;
			while (check)
			{
				if ((m_minutes + (60 * 24 * x) < D.m_minutes))	x++;
				else check = false;
			}

			temp.m_minutes = (m_minutes + (60 * 24 * x)) - D.m_minutes;

		}
		else
		{
			temp.m_minutes = m_minutes - D.m_minutes;
		}
		return temp;
	}
	Time& Time::operator+=(const Time& D)
	{
		m_minutes += D.m_minutes;
		return *this;
	}
	Time Time::operator+(const Time& D) const
	{
		Time temp(m_minutes + D.m_minutes);
		return temp;
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
		Time temp(this->m_minutes * val);
		return temp;
	}
	Time Time::operator/(unsigned int val) const
	{
		Time temp(this->m_minutes / val);
		return temp;
	}
	Time::operator unsigned int() const
	{
		return m_minutes;
	}
	Time::operator int() const
	{
		return (int)m_minutes;
	}
	unsigned Time::retHours() const
	{
		return (m_minutes / 60);
	}
	unsigned Time::retMinutes() const
	{
		return (m_minutes - (60 * retHours()));
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