//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :06/06/2021.
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{

	struct Population
	{
		char* p_name;
		int p_count;
	};

	void sort();
	bool load(const char* FILENAME);
	bool load(Population& pop);	
	void display(const Population& pop);
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_