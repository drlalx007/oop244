//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :30/05/2021.
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds
{
	class Label
	{
		char* frame;
		char* content;
		void setFrame(const char* str);
		void setContent(const char* str);
		void printLine() const;
	public:
		Label();
		Label(const char* arg);
		Label(const char* arg, const char* cont);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}

#endif // !SDDS_LABEL_H