#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Time.h"

using ui = unsigned int;

class bus		// ����� �������� ��������. ������ � ���� ����� ���� � ������ ��� ���� ����� ��������� � �������� ������� ��� ���
{
public:
	friend class bus_table;			// ����� ������� ��������� - �������������. ����� �������� ��������� ���� ������ bus.
	friend class Time;				// ����� ������� - �������������. ����� �������� ��������� ���� ������ bus.

	enum class Type { Default = 0, City_Bus, Intercity_Bus, Shuttle_Bus };

	bus(ui, std::string, Time, Time, Type);
	virtual void show_bus() const;
	friend fstream& operator<<(fstream& fs, const bus& b);

private:
	ui route_number;
	Type type = Type::Default;
	std::string finished_stop;
	Time time_to_leave;
	Time arrival_time;
};

