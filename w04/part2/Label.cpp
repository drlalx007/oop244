//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :30/05/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Label.h"
using namespace std;

namespace sdds
{
	void Label::setFrame(const char* strg)
	{
		if (strg != nullptr)
		{
			int length = strLen(strg);
			frame = new char[length + 1];
			strCpy(frame, strg);
		}
	}

	Label::Label()
	{
		content = nullptr;
		frame = new char[9];
		strCpy(frame, "+-+|+-+|");
	}

	Label::Label(const char* arg)
	{
		content = nullptr;
		setFrame(arg);
	}
	void Label::printLine() const
	{
		int idx = 0;
		while (content[idx])
		{
			cout << " ";
			idx++;
		}
		cout << "  ";
	}

	Label::Label(const char* arg, const char* cont)
	{
		setFrame(arg);
		setContent(cont);
	}

	void Label::readLabel()
	{
		content = new char[71];
		cin.getline(content, 71);
	}

	Label::~Label()
	{
		frame = nullptr;
		content = nullptr;
	}

	std::ostream& Label::printLabel() const
	{
		if (content != nullptr && strLen(content) > 0)
		{
			cout << frame[0];
			for (int i = 0; i < strLen(content) + 2; i++)
				cout << frame[1];
			cout << frame[2] << endl;
			cout << frame[7];
			printLine();
			cout << frame[3] << endl;

			cout << frame[7];
			cout << " " << content << " ";
			cout << frame[3] << endl;

			cout << frame[7];
			printLine();
			cout << frame[3] << endl;

			cout << frame[6];
			for (int i = 0; i < strLen(content) + 2; i++)
				cout << frame[5];
			cout << frame[4];
		}
		return cout;
	}

	void Label::setContent(const char* strg)
	{
		if (strg != nullptr)
		{
			int len = strLen(strg);
			content = new char[len + 1];
			strCpy(content, strg);
		}
	}
}

