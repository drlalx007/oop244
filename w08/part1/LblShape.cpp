/*
	Name: Darytl Alex
	ID : 143691202
	Email : dalex4@myseneca.ca
	Date: 22-07-2021
*/
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label()const {
		return m_label;
	}

	LblShape::LblShape() {}
	LblShape::LblShape(const char* label) {
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(std::istream& is) {
		string flag;
		getline(is, flag, ',');
		delete[] m_label;
		m_label = new char[strlen(flag.c_str()) + 1];
		strcpy(m_label, flag.c_str());
	}
}