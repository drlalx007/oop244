//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include<cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds
{
    Menu::Menu(const char* text, int NoOfSelections) :m_noofsel(NoOfSelections)
    {
        m_txt = new char[strlen(text) + 1];
        strcpy(m_txt, text);
    }

    Menu::~Menu()
    {
        delete[] m_txt;
    }


    Menu::Menu(const Menu& M)
    {
        m_txt = new char[strlen(M.m_txt) + 1];
        strcpy(m_txt, M.m_txt);
        m_noofsel = M.m_noofsel;
    }
    void Menu::display(void) const
    {
        cout << m_txt << endl << "0- Exit" << endl;
    }

    int& Menu::operator>>(int& Selection)
    {

        display();

        Selection = getInt(0, m_noofsel, "> ", "Invalid option ");

        return Selection;
    }




}