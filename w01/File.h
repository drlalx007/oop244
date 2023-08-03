//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :27/05/2021.
//"I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
#define _CRT_SECURE_NO_WARNINGS
#ifndef W1_FILE_H
#define W1_FILE_H
#include <cstdio>
#include "ShoppingRec.h"

namespace sdds{
    const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif //W1_FILE_H
