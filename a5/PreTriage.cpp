//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include "PreTriage.h"
#include "Time.h"
#include "CovidPatient.h"
#include "utils.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds
{
    PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
    {
        delete[] m_dataFilename;
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    }

    PreTriage::~PreTriage()
    {
        ofstream fin;
        fin.open(m_dataFilename);
        if (fin.is_open())
        {
            fin << m_averCovidWait << ',' << m_averTriageWait << endl;
            cout << "Saving Average Wait Times," << endl;
            cout << "   COVID Test: " << m_averCovidWait << endl;
            cout << "   Triage: " << m_averTriageWait << endl;
            cout << "Saving m_lineup...";

            for (int i = 0; i < m_lineupSize; i++)
            {
                m_lineup[i]->csvWrite(fin) << endl;
            }
            for (int j = 0; j < m_lineupSize; j++)
            {
                cout << '\n' << j + 1 << "- ";
                m_lineup[j]->csvWrite(cout);
            }
            fin.close();
        }
        else
        {
            cout << "Bad data in file" << endl;
        }
        for (int i = 0; i < maxNoOfPatients; i++)
        {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
        cout << '\n' << "done!" << endl;
    }


    const Time PreTriage::getWaitTime(const Patient& p)const
    {
        int count = 0;
        int wait = 0;
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (m_lineup[i]->type() == p.type())
            {
                count++;
            }
        }
        if (p.type() == 'C')
        {
            wait = m_averCovidWait;
            wait *= count;
        }
        else if (p.type() == 'T')
        {
            wait = m_averTriageWait;
            wait *= count;
        }
        return wait;
    }


    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        /*
        CT: Current Time
        PTT: Patient's Ticket Time
        AWT: Average Wait Time (Covid or Triage)
        PTN: Patient's Ticket Number
        AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
        */
        int CT = getTime();
        int PTT = p.operator sdds::Time();
        int PTN = p.number();
        if (p.type() == 'C')
        {
            int AWT = m_averCovidWait;
            m_averCovidWait = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
        }
        else if (p.type() == 'T')
        {
            int AWT = m_averTriageWait;
            m_averTriageWait = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
        }
    }


    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }



    int PreTriage::indexOfFirstInLine(char type) const
    {
        int flag = 0;
        int posn = -1;

        for (int i = 0; i < m_lineupSize && flag == 0; i++)
        {
            if (m_lineup[i]->type() == type)
            {
                posn = i;
                flag = 1;
            }

        }//end for loop
        return posn;
    }


    void PreTriage::load()
    {
        cout << "Loading data..." << endl;
        string str;
        char A;
        int count = 0;
        ifstream fin;
        fin.open(m_dataFilename);
        if (fin.is_open())
        {
            getline(fin, str, '\n');
            stringstream ss(str);
            ss >> m_averCovidWait >> A >> m_averTriageWait;
            ss.ignore('\n');
            for (int i = 0; i < maxNoOfPatients; i++)
            {
                Patient* temp = nullptr; //pointer
                if (!fin.fail() || !fin.eof())
                {
                    getline(fin, str, ',');
                    if (!strcmp(str.c_str(), "C"))
                    {
                        temp = new CovidPatient();
                    }
                    else if (!strcmp(str.c_str(), "T"))
                    {
                        temp = new TriagePatient();
                    }
                    if (temp != nullptr)
                    {
                        temp->fileIO(true);
                        temp->read(fin);
                        temp->fileIO(false);
                        m_lineup[i] = temp;
                        m_lineupSize++;

                    }
                }
                else
                {
                    i = maxNoOfPatients;
                }
            }
            while (getline(fin, str, ','))
            {
                count++;
            }
            if (count > 0)
            {
                cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
            }
            if (m_lineupSize > 0)
            {
                cout << m_lineupSize << " Records imported...\n\n";
            }
            else
            {
                cout << "No data or bad data file!" << endl << endl;
            }
            fin.close();
        }
        else
        {
            cout << "Error File Not Loading";
        }
    }

    void PreTriage::reg()
    {
        if (m_lineupSize >= maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
        }
        else
        {
            int selection = -1;
            int a = m_lineupSize;
            m_pMenu >> selection;
            if (selection == 1)
            {
                m_lineup[a] = new CovidPatient();
                m_lineup[a]->setArrivalTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[a]->fileIO(false);
                m_lineup[a]->read(cin);
                cout << "\n" << "******************************************" << endl;
                m_lineup[a]->write(cout);
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[a]) << endl;
                cout << "******************************************" << endl << endl;
                m_lineupSize++;
            }
            else if (selection == 2)
            {
                m_lineup[a] = new TriagePatient();
                m_lineup[a]->setArrivalTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[a]->fileIO(false);
                m_lineup[a]->read(cin);
                cout << "\n" << "******************************************" << endl;
                m_lineup[a]->write(cout);
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[a]) << endl;
                cout << "******************************************" << endl << endl;
                m_lineupSize++;
            }
        }
    }


    void PreTriage::admit()
    {
        int selection = -1;
        int a;
        m_pMenu >> selection;
        if (selection == 1)
        {
            a = indexOfFirstInLine('C');
            if (a != -1)
            {
                cout << '\n' << "******************************************" << '\n';
                m_lineup[a]->fileIO(false);
                cout << "Calling for ";
                m_lineup[a]->write(cout);
                cout << "******************************************" << '\n' << endl;
                setAverageWaitTime(*m_lineup[a]);
                removePatientFromLineup(a);
            }
        }
        else if (selection == 2)
        {
            a = indexOfFirstInLine('T');
            if (a != -1)
            {
                cout << '\n' << "******************************************" << '\n';
                m_lineup[a]->fileIO(false);
                cout << "Calling for ";
                m_lineup[a]->write(cout);
                cout << "******************************************" << '\n' << endl;
                setAverageWaitTime(*m_lineup[a]);
                removePatientFromLineup(a);
            }
        }
    }

    void PreTriage::run(void)
    {
        int selection = -1;
        while (selection != 0)
        {
            m_appMenu >> selection;
            if (selection == 1)
            {
                reg();
            }
            else if (selection == 2)
            {
                admit();
            }
        }
    }


}
