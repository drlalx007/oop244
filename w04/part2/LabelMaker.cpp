//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :30/05/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds
{
	LabelMaker::LabelMaker(int no_label)
	{
		m_no_label = no_label;
		m_label = new Label[no_label];
	}
	void LabelMaker::printLabels()
	{
		int i = 0;
		while (i < m_no_label)
		{
			m_label[i].printLabel() << endl;
			i++;
		}
	}
	LabelMaker::~LabelMaker()
	{
		for (int i = 0; i < m_no_label; i++)
		{
			m_label[i] = nullptr;
		}
		delete[] m_label;
	}
	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_no_label << " labels:" << endl;
		int i = 0;
		while (i < m_no_label)
		{
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			m_label[i].readLabel();
			i++;
		}
	}
}