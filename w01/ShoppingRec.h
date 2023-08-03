//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :27/05/2021.
//"I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
#define _CRT_SECURE_NO_WARNINGS
#ifndef W1_SHOPPINGREC_H
#define W1_SHOPPINGREC_H
#include "Utils.h"
#include <iostream>
namespace sdds{
    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;
    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif //W1_SHOPPINGREC_H
