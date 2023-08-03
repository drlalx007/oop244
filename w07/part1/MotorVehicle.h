//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :15/07/2021.

#ifndef SDDS_MOTORVEHICLE
#define SDDS_MOTORVEHICLE
#include<iostream>
namespace sdds
{

	class MotorVehicle
	{
		char licene_plate[10];
		char current_address[65];
		int year_of_manu;
	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& out) const;
		std::istream& read(std::istream& in);

	};

	std::istream& operator>>(std::istream& in, MotorVehicle& v);
	std::ostream& operator<<(std::ostream& out, const MotorVehicle& v);
}
#endif // !SDDS_MOTORVEHICLE
