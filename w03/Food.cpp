//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :13/06/2021.

#define _CRT_SECURE_NO_WARNINGS


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "cstring.h"
#include "Food.h"

const double TAX = 0.13;
using namespace std;
namespace sdds
{

	void Food::setName(const char* name)
	{
		strnCpy(c_foodName, name, 30); //
		c_foodName[30] = char(0); //null character
	}
	void Food::setEmpty()
	{
		c_foodName[0] = char(0); //null
		c_CalorieNumb = 0;
		c_TimeConsump = 0;

	}
	void Food::set(const char* name, int calno, int time)
	{

		if (calno > 0 && name != nullptr)
		{
			setName(name);
			c_CalorieNumb = calno;
			c_TimeConsump = time;
		}
		else
		{
			setEmpty();
		}

	}
	void Food::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(30);
			if ((c_TimeConsump == 1) || (c_TimeConsump == 2) || (c_TimeConsump == 3) || (c_TimeConsump == 4))
			{

				cout.fill('.');
				cout << c_foodName;
			}
			else
			{
				cout.fill('x');
				cout << "x";
			}


			cout.fill(' ');
			cout << " | ";
			cout.width(4);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.unsetf(ios::left);
			cout.setf(ios::right);

			if ((c_TimeConsump == 1) || (c_TimeConsump == 2) || (c_TimeConsump == 3) || (c_TimeConsump == 4))
			{
				cout << c_CalorieNumb;
			}
			else
			{
				cout << "xxxx";
			}

			if (c_TimeConsump == 1)
			{
				cout << " | " << "Breakfast  |" << endl;
			}
			else if (c_TimeConsump == 2)
			{
				cout << " | " << "Lunch      |" << endl;
			}
			else if (c_TimeConsump == 3)
			{
				cout << " | " << "Dinner     |" << endl;
			}
			else if (c_TimeConsump == 4)
			{
				cout << " | " << "Snack      |" << endl;
			}
			else
			{
				cout << " | " << "xxxxxxxxxx |" << endl;
			}
			cout.unsetf(ios::right);
		}
		else
		{
			cout << "| ";
			cout.width(30);
			cout.fill('x');
			cout << 'x';
			cout << " | ";
			cout.width(4);
			cout << 'x';
			cout << " | xxxxxxxxxx |" << endl;
		}

	}

	bool Food::isValid()const
	{
		bool ok = false;
		if ((c_TimeConsump == 1) || (c_TimeConsump == 2) || (c_TimeConsump == 3) || (c_TimeConsump == 4))
		{
			if (c_foodName[0] != char(0))
			{
				ok = true;
			}
		}

		return ok;
	}

	double Food::calorie()const
	{
		return c_CalorieNumb;
	}
}