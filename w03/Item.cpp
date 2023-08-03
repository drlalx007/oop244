//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :10/06/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Item.h"

const double TAX = 0.13;
using namespace std;
namespace sdds
{

	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = char(0);
	}

	void Item::setEmpty()
	{
		m_itemName[0] = char(0);
		m_price = 0.0;
		m_taxed = true;
	}
	void Item::set(const char* name, double price, bool taxed)
	{

		if (price > 0.0 && name != nullptr)
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		else
		{
			setEmpty();
		}

	}
	void Item::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_itemName;
			cout.fill(' ');
			cout << " | ";
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout << m_price;
			cout << " | " << (m_taxed ? "Yes |" : "No  |") << endl;
			cout.unsetf(ios::right);
		}
		else
		{
			cout << "| ";
			cout.width(20);
			cout.fill('x');
			cout << 'x';
			cout << " | ";
			cout.width(7);
			cout << 'x';
			cout << " | xxx |" << endl;
		}

	}
	bool Item::isValid()const
	{
		return m_itemName[0] != char(0);
	}

	double Item::price()const
	{
		return m_price;
	}
	double Item::tax()const
	{
		if (m_taxed)
		{
			return m_price * TAX;
		}
		else
		{
			return 0.0;
		}
	}
}