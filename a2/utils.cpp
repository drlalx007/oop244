//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :17/07/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
    bool debug = false;  
    int getTime() {
        int minutes = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t; 
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    minutes = int(t);
                }
                cin.ignore(1000, '\n');
            } while (minutes < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            minutes = lt.tm_hour * 60 + lt.tm_min;
        }
        return minutes;
    }

    int getInt(const char* prompt)
    {
        bool badEntry;
        char next_char;
        int flag;
        if (prompt)cout << prompt;
        do
        {
            badEntry = false;
            cin >> flag;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(3000, '\n');
                badEntry = true;
            }
            else
            {
                next_char = cin.get();
                if (next_char != '\n')
                {
                    cout << "Enter only an integer, try again: ";
                    cin.ignore(3000, '\n');
                    badEntry = true;
                }
            }


        } while (badEntry);
        return flag;
    }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
    {
        int value;
        value = getInt(prompt);
        while (value<min || value>max)
        {
            if (errorMessage)cout << errorMessage;
            if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";
            value = getInt();
        }
        return value;
    }


    char* getcstr(const char* prompt, std::istream& istr, char delimiter)
    {
        if (prompt)
        {
            cout << prompt;
        }
        char* S = nullptr;
        string temp;
        getline(istr, temp);
        S = new char[strlen(temp.c_str()) + 1];
        strcpy(S, temp.c_str());
        return S;
    }



}