//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :03/08/2021.

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <string>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds
{
    Patient::Patient(int ticketNumber, bool fileIO) :
        m_name{ nullptr }, m_ohip{}, m_ticket(ticketNumber),
        m_fileIO{ fileIO } {}

    Patient::operator Time() const
    {
        return Time(m_ticket);
    }

    int Patient::number() const
    {
        return m_ticket.number();
    }


    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }


    void Patient::fileIO(bool value)
    {
        m_fileIO = value;
    }


    bool Patient::fileIO()const
    {
        return m_fileIO;
    }

    std::ostream& Patient::csvWrite(std::ostream& ostr)const
    {
        ostr << type() << "," << m_name << "," << m_ohip << ",";
        return m_ticket.csvWrite(ostr);

    }

    std::istream& Patient::csvRead(std::istream& istr)
    {
        delete[] m_name;
        string str;
        getline(istr, str, ',');
        m_name = new char[str.length() + 1];
        strcpy(m_name, str.c_str());

        istr >> m_ohip;
        istr.ignore(1000, ',');
        return m_ticket.csvRead(istr);

    }

    std::ostream& Patient::write(std::ostream& ostr)const
    {
        ostr << m_ticket << endl;
        prnName(ostr);
        ostr << ", OHIP: " << m_ohip;
        return ostr;
    }

    std::istream& Patient::read(std::istream& istr)
    {
        delete[] m_name;
        m_name = getcstr("Name: ");
        m_ohip = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ");
        return istr;
    }

    std::ostream& Patient::prnName(std::ostream& ostr)const
    {
        for (int i = 0; m_name[i] && i < 25; i++)ostr << m_name[i];
        return ostr;
    }


    bool Patient::operator==(char Objtype)const
    {
        return Objtype == type();

    }


    bool Patient::operator==(const Patient& P)const
    {
        return type() == P.type();
    }

    Patient::~Patient()
    {
        delete[] m_name;
        m_name = nullptr;
    }



}
