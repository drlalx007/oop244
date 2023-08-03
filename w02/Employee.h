//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/06/2021.
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"

namespace sdds
{
	struct Employee
	{
		char* m_name;
		int m_empNo;
		double m_salary;
	};

	void sort();

	bool load(Employee& EMP);
	bool load();

	void display(const Employee& EMP);

	void display();

	void deallocateMemory();

}
#endif // SDDS_EMPLOYEE_H_