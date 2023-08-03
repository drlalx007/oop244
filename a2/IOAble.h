//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :17/07/2021.

#ifndef SDDS_IOABLE
#define SDDS_IOABLE
#include <iostream>
namespace sdds
{
	class IOAble
	{
	public:
		virtual std::ostream& csvWrite(std::ostream& ostr)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble();
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& IO);
	std::istream& operator>>(std::istream& istr, IOAble& IO);
}

#endif //SDDS_IOABLE