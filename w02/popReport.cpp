//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :06/06/2021.
#include "Population.h"
using namespace sdds;
int main() {
	if (load("PCpopulations.csv"))
	{
        display();
    }
    deallocateMemory();
    return 0;
}