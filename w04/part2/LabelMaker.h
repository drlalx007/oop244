//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :30/05/2021.
#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_
#include "Label.h"
namespace sdds
{
	class LabelMaker
	{
		Label* m_label;
		int m_no_label;
	public:
		LabelMaker(int no_label);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif 
