//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :15/07/2021.

#include<iostream>
#include<iomanip>
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds
{

	MotorVehicle::MotorVehicle(const char* plate, int year)
	{
		this->year_of_manu = year;
		strCpy(this->licene_plate, plate);
		strCpy(this->current_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address)
	{
		cout << "|" << right << setw(8) << this->licene_plate << "| |" << setw(20) << right << this->current_address << " ---> " << setw(20) << left << address << "|\n";
		strCpy(this->current_address, address);
	}


	ostream& MotorVehicle::write(std::ostream& out) const
	{
		out << "| ";
		out << this->year_of_manu;
		out << " | ";
		out << this->licene_plate;
		out << " | ";
		out << this->current_address;
		return out;

	}

	istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> this->year_of_manu;
		cout << "License plate: ";
		in >> this->licene_plate;
		cout << "Current location: ";
		in >> this->current_address;
		return in;
	}

	istream& operator>>(std::istream& in, MotorVehicle& v)
	{
		return v.read(in);
	}

	ostream& operator<<(std::ostream& out, const MotorVehicle& v)
	{
		return v.write(out);
	}




}