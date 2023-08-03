//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :17/07/2021.
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds
{
    extern bool debug; 

    int getTime(); 

    int getInt(
        const char* prompt = nullptr   
    );

    int getInt(
        int u_minimum,   
        int U_maximum,   
        const char* prompt = nullptr,  
        const char* err_msg = nullptr,  
        bool show_err = true    
    );

    char* getcstr(
        const char* prompt = nullptr,   
        std::istream& istr = std::cin,  
        char eod = '\n'    
    );

}
#endif // !SDDS_UTILS_H_

