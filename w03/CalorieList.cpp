//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :13/06/2021.


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
#include "Food.h"

using namespace std;
namespace sdds
{


    double CalorieList::totalCal()const
    {
        int CAL = 0;
        for (int i = 0; i < c_size; i++)
        {
            CAL += c_food[i].calorie();
        }
        return CAL;
    }
    void CalorieList::Title()const
    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|";
            cout.width(36);
            cout.fill(' ');
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout << "  Daily Calorie Consumption                         ";
            cout << "|" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }
    void CalorieList::footer()const
    {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {

            int cal = totalCal();
            cout << "|    Total Calories for today:";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.precision(2);
            cout.fill(' ');
            cout.width(9);
            cout << cal << " |            |" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;

    }

    void CalorieList::setEmpty()
    {

        c_food = nullptr;
    }

    bool CalorieList::isValid()const
    {
        bool valid = false;
        if (c_food != nullptr)
        {
            for (int i = 0; i < c_size; i++)
            {
                valid = c_food[i].isValid();
                if (!valid) {
                    break;
                }
            }
            return valid;
        }
        else
        {
            return valid;
        }
    }


    void CalorieList::init(int size)
    {
        if (size > 0)
        {

            c_food = new Food[size];
            for (int i = 0; i < size; i++)
            {
                c_food[i].setEmpty();

            }
            c_size = size;
            c_foodAdded = 0;
        }
        else
        {
            setEmpty();
        }
    }
    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        bool ok = false;
        if (c_foodAdded < c_size)
        {
            c_food[c_foodAdded++].set(item_name, calories, when);
            ok = true;
        }
        return ok;

    }
    void CalorieList::display()const
    {
        Title();
        for (int i = 0; i < c_size; i++)
        {
            c_food[i].display();
        }

        footer();
    }
    void CalorieList::deallocate()
    {
        delete[] c_food;
        c_food = nullptr;
    }

}