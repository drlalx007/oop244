//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :06/06/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include <cstring>
#include "File.h"
using namespace std;
namespace sdds
{
	int numRecords;
	Population* pop;
	void sort() 
	{
		int i, j;
		Population temp;
		for (i = numRecords - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (pop[j].p_count > pop[j + 1].p_count) {
					temp = pop[j];
					pop[j] = pop[j + 1];
					pop[j + 1] = temp;
				}
			}
		}
	}
	bool load(Population& pop)
	{
		bool ok = false;
		char name[128];
		bool val1, val2;	
		val1 = read(name);
		val2 = read(pop.p_count);		
		if (val1 == true && val2 == true )
		{
			int len = strlen(name);
			pop.p_name = new char[len + 1];
			strcpy(pop.p_name, name);
			ok = true;
		}
		else
		{
			cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
		}
		return ok;
	}
	bool load(const char* FILENAME)
	{
		bool ok = false;
		int i = 0;
		if (openFile(FILENAME))
		{
			numRecords = noOfRecords(); 
			pop = new Population[numRecords];
			for (i = 0; i < numRecords; i++) 
			{
				ok = load(pop[i]); 
			}
			closeFile();
		}
		else 
		{
			cout <<" Could not open data file : FILENAME"<< endl;
		}
		return ok;
	}
	void display(const Population& pop)
	{
		cout << pop.p_name << ":  " << pop.p_count << endl;
	}


	void display()
	{
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		sort(); 
		int i;
		for (i = 0; i < numRecords; i++)
		{
			cout << i + 1 << "- ";
			display(pop[i]);
		}
		
		
		int TotalCount = 0;
		for (i = 0; i < numRecords; i++)
		{
			TotalCount += pop[i].p_count;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << TotalCount << endl;

	}
	void deallocateMemory()
	{
		int i = 0;
		for (i = 0; i < numRecords; i++)
		{
			delete[] pop[i].p_name;
		}
		delete[] pop;
	}
}