#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h" // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
const double PI = 3.14159265;
namespace sdds {
	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13;
		m_diameter = 10;
		m_contentVolume = 0.0;
		m_usable = true;
	}
	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr && m_usable == true)
		{
			if (m_contentName)
				delete[] m_contentName;
			int length = strLen(Cstr);
			m_contentName = new char[length + 1];
			strCpy(m_contentName, Cstr);
		}
	}
	bool Canister::hasSameContent(const Canister& C) const
	{
		if (m_contentName != nullptr && C.m_contentName != nullptr)
		{
			int flag = strCmp(m_contentName, C.m_contentName);
			return flag == 0;
		}
		return false;
	}
	bool Canister::isEmpty() const
	{
		return m_contentVolume < 0.00001;
	}
	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}
	Canister::Canister()
	{
		setToDefault();
	}
	Canister::Canister(double hieght, double diameter, const char* contentName)
	{
		setToDefault();
		if (hieght >= 10.0 && hieght <= 40.0 && diameter >= 10.0 && diameter <= 30.0)
		{
			m_height = hieght;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}
	Canister::~Canister()
	{
		if (m_contentName && strLen(m_contentName) > 0)
			delete[] m_contentName;
	}
	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
	double Canister::volume() const
	{
		return m_contentVolume;
	}
	double Canister::capacity() const
	{
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}
	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr)
		{
			m_usable = false;
		}
		else if (isEmpty())
		{
			setName(contentName);
		}
		else if (strCmp(m_contentName, contentName) != 0)
		{
			m_usable = false;
		}
		return *this;
	}
	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);
		if (C.volume() > (capacity() - volume()))
		{
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else
		{
			C = pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}
	Canister& Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0.0)
		{
			if ((quantity + m_contentVolume) <= capacity())
			{
				m_contentVolume += quantity;
			}
			else
			{
				m_usable = false;
			}
		}
		else
		{
			m_usable = false;
		}
		return *this;
	}
	std::ostream& Canister::display() const
	{
		cout << fixed << setprecision(1);
		cout.width(7);
		cout << right << capacity();
		cout << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (m_usable == false)
		{
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr)
		{
			cout << " of ";
			cout.width(7);
			cout << m_contentVolume;
			cout << "cc   ";
			cout << m_contentName;
		}
		return cout;
	}
}