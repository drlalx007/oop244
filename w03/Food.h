//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :13/06/2021.


#define _CRT_SECURE_NO_WARNINGS


#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds
{
	class Food
	{
		char c_foodName[31];
		int c_CalorieNumb;
		int c_TimeConsump;

		void setName(const char* name); 
	public:

		void setEmpty();
		void set(const char* name, int calno, int time);
		void display()const;
		bool isValid()const;
		double calorie()const;
	};
}

#endif // !SDDS_SUBJECT_H
