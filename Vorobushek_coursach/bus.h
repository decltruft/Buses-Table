#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Time.h"

using ui = unsigned int;

class bus		// класс описания автобуса. хранит в себе общие поля и методы для всех типов автобусов и является базовым для них
{
public:
	friend class bus_table;			// класс таблицы маршрутов - дружественный. может изменять приватные поля класса bus.
	friend class Time;				// класс времени - дружественный. может изменять приватные поля класса bus.

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

