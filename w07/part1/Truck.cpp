//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :15/07/2021.

#include<iostream>
#include<iomanip>
#include "cstring.h"
#include "MotorVehicle.h"
#include "Truck.h"
using namespace std;

namespace sdds
{
	Truck::Truck(const char* plate, int year, double capacity, const char* address) :MotorVehicle(plate, year)
	{
		this->cap = capacity;
		this->shipping = 0;
		this->moveTo(address);
	}

	bool Truck::addCargo(double shipping)
	{
		if (this->shipping < this->cap)
		{
			if (this->shipping + shipping > this->cap)
			{
				this->shipping = this->cap;

			}
			else
			{
				this->shipping += shipping;
			}
			return true;
		}
		return false;
	}

	bool Truck::unloadCargo()
	{
		bool unload = this->shipping > 0;
		this->shipping = 0;
		return unload;
	}

	std::ostream& Truck::write(std::ostream& out)const
	{
		MotorVehicle::write(out);
		out << " | ";
		out << this->shipping << "/" << this->cap;
		return out;
	}

	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> this->cap;
		cout << "Cargo: ";
		in >> this->shipping;
		return in;
	}

	std::istream& operator>>(std::istream& in, Truck& T)
	{
		return T.read(in);
	}

	std::ostream& operator<<(std::ostream& out, const Truck& T)
	{
		return T.write(out);
	}

}
