//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :10/06/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Bill.h"
#include "Item.h"
using namespace std;
namespace sdds
{

    double Bill::totalTax()const
    {
        double totalTax = 0.0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            totalTax += m_items[i].tax();
        }


        return totalTax;
    }

    void Bill::Title()const
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.width(36);
            cout.fill(' ');
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout << m_title;
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    double Bill::totalPrice()const
    {
        double price = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            price += m_items[i].price();
        }
        return price;
    }



    void Bill::footer()const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            double tax = totalTax();
            double price = totalPrice();

            cout << "|                Total Tax: ";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.precision(2);
            cout.fill(' ');
            cout.width(10);
            cout << tax << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout << price << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << price + tax << " |" << endl;


        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;

    }


    void Bill::setEmpty()
    {
        m_title[0] = char(0);
        m_items = nullptr;
    }


    bool Bill::isValid()const
    {
        //Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
        bool valid = false;
        if (m_title[0] != char(0) && m_items != nullptr)
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                valid = m_items[i].isValid();

            }
            return valid;
        }
        else
        {
            return valid;
        }
    }


    void Bill::init(const char* title, int noOfItems)
    {
        if (title != nullptr && noOfItems > 0)
        {
            strnCpy(m_title, title, 36);
            m_items = new Item[noOfItems];
            for (int i = 0; i < noOfItems; i++)
            {
                m_items[i].setEmpty();

            }
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
        }
        else
        {
            setEmpty();
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool ok = false;
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded++].set(item_name, price, taxed);
        }
        return ok;

    }

    void Bill::display()const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }


}