//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :15/07/2021.

#ifndef SDDS_TRUCK
#define SDDS_TRUCK
#include<iostream>
#include "MotorVehicle.h"
namespace sdds
{
	class Truck :public MotorVehicle
	{
		double cap;
		double shipping;
	public:
		Truck(const char* plate, int year, double capacity, const char* address);
		bool addCargo(double shipping);
		bool unloadCargo();
		std::ostream& write(std::ostream& out)const;
		std::istream& read(std::istream& in);

	};
	std::istream& operator>>(std::istream& in, Truck& c);
	std::ostream& operator<<(std::ostream& out, const Truck& c);

}
#endif // !SDDS_TRUCK
