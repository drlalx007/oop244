//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/06/2021.
#include <iostream>
#include "cstring.h" 
#include "Employee.h"
#include "File.h"
#define DATAFILE "employees.csv"
using namespace std;
namespace sdds
{
    int noOfEmployees;
    Employee* employees;




    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    bool load(Employee& EMP) {
        bool ok = false;
        char name[128];
        bool val1, val2, val3;
        val2 = read(EMP.m_empNo);
        val3 = read(EMP.m_salary);
        val1 = read(name);
        if (val1 == true && val2 == true && val3 == true)
        {
            int len = strLen(name);
            EMP.m_name = new char[len + 1];
            strCpy(EMP.m_name, name);
            ok = true;
        }
        else
        {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
        }

        return ok;
    }

    bool load() {
        bool ok = false;
        int i = 0;


        if (openFile(DATAFILE))
        {
            noOfEmployees = noOfRecords();

            employees = new Employee[noOfEmployees];

            //for (i = 0; i < noOfEmployees && load(employees[i]); i++) 
            for (i = 0; i < noOfEmployees; i++)
            {
                ok = load(employees[i]);
            }


            closeFile();

        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        int i;
        for (i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }


    void display(const Employee& EMP)
    {
        cout << EMP.m_empNo << ": " << EMP.m_name << ", " << EMP.m_salary << endl;
    }


    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        int i = 0;
        for (i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }
        delete[] employees;
    }


}

