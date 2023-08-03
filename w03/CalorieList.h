//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :13/06/2021.h

#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "Food.h"


#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
namespace sdds
{
	class CalorieList
	{
		char c_title[37];
		Food* c_food;
		int c_size;
		int c_foodAdded;


		double totalCal()const;
		void Title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;

	public:
		void init(int size);  //accept the "size" number of Food Items. 
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();


	};
}

#endif // !SDDS_SUBJECT_H


