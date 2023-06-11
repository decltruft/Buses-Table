#pragma once

#include <iostream>
#include <fstream>

using ui = unsigned int;
using std::fstream;

class Time				// ����� ������� - �������� ���� � ������ ��� ������ � ����������� ���������� ������� (��� �������� ������� �������� � �������� ���������)
{
public:
	friend class bus;

	Time(ui h = 0, ui m = 0);
	void show_time() const;
	friend fstream& operator>>(fstream& fs, Time& t);
	Time& operator=(ui);

	ui get_h() const { return hourse; }
	ui get_m() const { return minutes; }

private:
	ui hourse;
	ui minutes;
};

