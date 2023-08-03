//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :28/06/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
    void Account::setEmpty() {
        a_number = -1;      
        a_balance = 0.0;
    }
    

    Account::Account() {     
        a_number = 0;       
        a_balance = 0.0;
    }
    
    Account::Account(int number, double balance) {
        setEmpty();   
        //check for valid data
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            a_number = number;
            a_balance = balance;
        }
    }
    
    std::ostream& Account::display() const { 
        if (*this) {
            cout << " ";
            cout << a_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << a_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const
    {
        return (a_number >= 10000 && a_number <= 99999);
    }


    Account::operator int() const {
        return a_number;
    }


    Account::operator double() const
    {
        return a_balance;
    }

    bool Account::operator~() const
    {
        bool flag = false;
        if (a_number == 0)
        {
            flag = true;
        }
        return flag;
    }


    Account& Account::operator=(int value) 
    {
        if (~*this) 
        {
            if (value >= 10000 && value <= 99999)
            {
                a_number = value;
            }
            else //invalid condition
            {
                setEmpty();
            }
        }
        return *this;
    }

    Account& Account::operator=(Account& new_accno) 
    {
        if (~*this && new_accno)
        {
            a_number = new_accno.a_number;
            a_balance = new_accno.a_balance;
            new_accno.a_number = 0;
            new_accno.a_balance = 0.0;
        }
        return *this;
    }


    Account& Account::operator+=(double value)
    {
        if (*this && value >= 0)
        {
            a_balance += value;
        }
        return *this;
    }


    Account& Account::operator-=(double value) 
    {
        if (*this && value >= 0 && value <= a_balance)
        {
            a_balance -= value;
        }
        return *this;
    }


    Account& Account::operator<<(Account& acc) 
    {
        if (*this && acc && this != &acc)
        {
                a_balance += acc.a_balance;
            acc.a_balance = 0.0;
        }
        return *this;
    }


    Account& Account::operator>>(Account& acc) 
    {
        if (*this && acc && this != &acc)
        {
            acc.a_balance += a_balance;
            a_balance = 0.0;
        }
        return *this;
    }


    double operator+(const Account& left, const Account& right)
    {
        double flag = 0;
        if (left && right)
        {
            flag = double(left) + double(right);
        }
        return flag;
    }


    double operator+=(double& left, const Account& right)
    {
        left += double(right);
        return left;
    }



}


