//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :30/05/2021.
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main()
{
    int noOfLabels;
    Label
        theProgram("/-\\|/-\\|", "The Label Maker Program"),
        EmptyOne1,
        EmptyOne2("ABCDEFGH");
    cout << "EmptyOne1" << endl;
    cout << endl;
    cout << "EmptyOne2" << endl;
    cout << endl;
    theProgram.printLabel() << endl << endl;
    cout << "Number of labels to create: ";
    cin >> noOfLabels;
    cin.ignore(10000, '\n');
    LabelMaker lblMkr(noOfLabels);
    lblMkr.readLabels();
    lblMkr.printLabels();
    return 0;
}