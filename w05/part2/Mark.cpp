#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Mark.h"
using namespace std;
namespace sdds {
	void Mark::setEmpty() {
		m_score = 0;
		setValid();
	}
	void Mark::setValid()
	{
		m_valid = 1;
	}
	void Mark::setInvalid()
	{
		m_valid = 0;
	}

	Mark::Mark()//default constructor
	{
		m_score = 0;
		setValid();
	}
	Mark::Mark(int mark) {//parameterized constructor
		setEmpty();
		bool valid = isValid(mark);
		if (valid && bool(m_valid))
		{
			m_score = mark;
		}
		else
		{
			setInvalid();
		}
	}
	bool Mark::isValid(int value)
	{
		int min_score = 0;
		int max_score = 100;
		bool check = false;
		if (value >= min_score && value <= max_score)
		{
			check = true;
		}
		return check;
	}
	void Mark::correctContent()
	{
		m_score = 0;
		setInvalid();
	}
	Mark::operator bool()const
	{
		return m_valid != 0;
	}
	Mark::operator double()const
	{
		int score = -1;
		if (!bool(m_valid))
		{
			score = 0;
		}
		else if (m_score >= 0 && m_score < 50)
		{
			score = 0;
		}
		else if (m_score >= 50 && m_score < 60)
		{
			score = 1;
		}
		else if (m_score >= 60 && m_score < 70)
		{
			score = 2;
		}
		else if (m_score >= 70 && m_score < 80)
		{
			score = 3;
		}
		else if (m_score >= 80 && m_score <= 100)
		{
			score = 4;
		}
		else
		{
			score = 0;
		}
		return score;
	}
	Mark::operator int() const
	{
		return m_score;
	}
	Mark::operator char()const
	{
		char score = -1;
		if (!bool(m_valid))
		{
			score = char(88);
		}
		else if (m_score >= 0 && m_score < 50)
		{
			score = char(70);
		}
		else if (m_score >= 50 && m_score < 60)
		{
			score = char(68);
		}
		else if (m_score >= 60 && m_score < 70)
		{
			score = char(67);
		}
		else if (m_score >= 70 && m_score < 80)
		{
			score = char(66);
		}
		else if (m_score >= 80 && m_score <= 100)
		{
			score = char(65);
		}
		else
		{
			score = char(88);
		}
		return score;
	}
	bool Mark::operator~() const
	{
		bool new_score = false;
		if (m_valid == 1)
		{
			new_score = true;
		}
		return new_score;
	}
	Mark& Mark::operator=(int value)
	{
		bool flag = isValid(value);
		if (!flag)
		{
			setEmpty();
			setInvalid();
		}
		else
		{
			setValid();
			m_score = value;
		}
		return *this;
	}

	Mark& Mark::operator+=(int value)
	{
		int sum_score = m_score += value;
		bool check_value = isValid(value);
		bool check_sum = isValid(sum_score);
		if (m_valid == 0 || !check_value || !check_sum)
		{
			correctContent();
		}
		return *this;
	}
	double Mark::getMark() const
	{
		return m_score;
	}
	double operator+=(int& value, const Mark& RightOperand)
	{
		value += RightOperand.getMark();
		return value;
	}
}