//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :17/07/2021.
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr.fill('0');
		ostr.width(2);
		ostr << RHours() << ":";
		ostr.fill('0');
		ostr.width(2);
		ostr << RMinutes();
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int m_hrs = 0;
		int mins = 0;
		char a = '\0';
		istr >> m_hrs;
		if (m_hrs < 0)
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			m_min = m_hrs * 60;
		}
		istr.get(a);
		if (a != ':')
		{
			istr.setstate(ios::failbit);
		}

		istr >> mins;
		if (mins < 0)
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			m_min += mins;
		}

		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		bool choice = true;
		if (m_min < D.m_min)
		{
			int x = 1;
			while (choice)
			{
				if ((m_min + (60 * 24 * x) < D.m_min))
				{
					x++;
				}
				else
				{
					choice = false;
				}
			}

			m_min += (60 * 24 * x);
			m_min -= D.m_min;
		}
		else
		{
			m_min -= D.m_min;
		}
		return *this;
	}

	Time Time::operator-(const Time& D) const
	{
		bool choice = true;
		Time temp;
		if (m_min < D.m_min)
		{
			int x = 1;
			while (choice)
			{
				if ((m_min + (60 * 24 * x) < D.m_min))	x++;
				else choice = false;
			}

			temp.m_min = (m_min + (60 * 24 * x)) - D.m_min;

		}
		else
		{
			temp.m_min = m_min - D.m_min;
		}
		return temp;
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D) const
	{
		Time temp(m_min + D.m_min);
		return temp;
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time::operator*(unsigned int val) const
	{
		Time temp(this->m_min * val);
		return temp;
	}

	Time Time::operator/(unsigned int val) const
	{
		Time temp(this->m_min / val);
		return temp;
	}

	Time::operator unsigned int() const
	{
		return m_min;
	}

	Time::operator int() const
	{
		return (int)m_min;
	}

	unsigned Time::RHours() const
	{
		return (m_min / 60);
	}

	unsigned Time::RMinutes() const
	{
		return (m_min - (60 * RHours()));
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