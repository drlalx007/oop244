//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :28/06/2021.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
	class Account
	{
		int a_number;
		double a_balance;
		void setEmpty();
	public:
		Account();
		Account(int number, double balance);
		std::ostream& display()const;
		operator bool() const;
		operator int() const;
		operator double() const;
		bool operator ~() const;
		Account& operator=(int);
		Account& operator=(Account&);
		Account& operator+=(double);
		Account& operator-=(double);
		Account& operator<<(Account&);
		Account& operator>>(Account&);
	};
	double operator+(const Account& left, const Account& right);
	double operator+=(double& left, const Account& right);

}
#endif // SDDS_ACCOUNT_H_