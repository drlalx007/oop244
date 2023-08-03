//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :27/05/2021.
//"I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
#define _CRT_SECURE_NO_WARNINGS
#ifndef W1_UTILS_H
#define W1_UTILS_H
#include <iostream>
namespace sdds{
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}

#endif //W1_UTILS_H
