//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :22/07/2021.

#include<iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT
#define SDDS_PATIENT
namespace sdds
{
    class Patient :public IOAble
    {
        char* m_name = nullptr;
        int m_ohip = 0;
        Ticket m_ticket;
        bool m_fileIO;
        std::ostream& prnName(std::ostream& ostr)const;
    public:
        Patient(int ticketNumber = 0, bool fileIO = false);
        ~Patient();
        Patient(const Patient&) = delete;
        Patient& operator=(const Patient&) = delete;
        void fileIO(bool yes);
        bool fileIO()const;
        virtual char type()const = 0;
        std::ostream& csvWrite(std::ostream& ostr)const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
        bool operator==(char type)const;
        bool operator==(const Patient& P)const;
        operator Time()const;
        int number()const;
        void setArrivalTime();
    };
}

#endif // !SDDS_PATIENT
