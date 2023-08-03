//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :12/07/2021.

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
	int getTime()
	{


		int min = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do

			{
				cin.clear();
				cin >> t;


				if (!cin) {
					cout << "Invlid time, try agian (HH:MM): ";


					cin.clear();
				}
				else {
					min = int(t);


				}
				cin.ignore(1000, '\n');
			} while (min < 0);
		}
		else {


			time_t t = time(NULL);
			tm lt = *localtime(&t);
			min = lt.tm_hour * 60 + lt.tm_min;
		}


		return min;
	}

	int getInt(const char* prompt)
	{
		int okay = 0;
		bool valid = false;
		int nos;
		if (prompt != nullptr)
			cout << prompt;
		string line;
		getline(cin, line);
		line = line + '\n';

		while (okay != 2)
		{
			nos = 0;
			int x = 0;
			while (line[x])
			{
				if (!isdigit(line[x]))
				{
					if (!valid)
						okay = 0;
					else if (line[x] == '\n')
						okay = 2;
					else
						okay = 1;
					break;
				}
				else
				{
					valid = true;
					nos = nos * 10 + line[x] - '0';
				}
				x++;
			}
			if (okay != 2)
			{
				if (okay == 0)
					cout << "Bad integer value, try again: ";
				else
					cout << "Enter only an integer, try again: ";
				getline(cin, line);
				line = line + '\n';
			}
		}
		return nos;
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		int flag = 0;
		bool check = false;
		int nos;
		if (prompt != nullptr)
			cout << prompt;
		string A;
		getline(cin, A);
		A = A + '\n';

		while (flag != 2)
		{
			nos = 0;
			int x = 0;
			while (A[x])
			{
				if (!isdigit(A[x]))
				{
					if (!check)
						flag = 0;
					else if (A[x] == '\n')
						flag = 2;
					else
						flag = 1;
					break;
				}
				else
				{
					check = true;
					nos = nos * 10 + A[x] - '0';
				}
				x++;
			}
			if (flag != 2)
			{
				if (flag == 0)
					cout << "Bad integer value, try again: ";
				else
					cout << "Enter only an integer, try again: ";
				getline(cin, A);
				A = A + '\n';
			}
			else if (nos < min || nos > max)
			{
				flag = 0;
				if (errorMessage != nullptr)
					cout << errorMessage;
				if (showRangeAtError)
				{
					cout << "[" << min << " <= value <= " << max << "]: ";
				}
				getline(cin, A);
				A = A + '\n';
			}
		}
		return nos;
	}


	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		if (prompt)
		{
			cout << prompt;
		}

		char* line = nullptr;
		string temp;
		getline(istr, temp);
		line = new char[strlen(temp.c_str()) + 1];
		strcpy(line, temp.c_str());
		return line;
	}

}