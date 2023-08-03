//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.
#ifndef SDDS_MENU
#define SDDS_MENU
#include<iostream>
namespace sdds
{

    class Menu
    {
        char* m_txt;
        int m_noofsel;
        void display()const;
    public:
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        Menu(const Menu&);

        int& operator>>(int& Selection);
    };
}
#endif // !SDDS_MENU

