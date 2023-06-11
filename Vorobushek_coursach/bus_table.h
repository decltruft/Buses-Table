#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "bus.h"
#include "bad_opened_file.h"
#include "Time.h"

using ui = unsigned int;

class bus_table
{
public:
	struct bus_buff
	{
		ui route_number;
		bus::Type type;
		std::string finished_stop;
		Time time_to_leave;
		Time arrival_time;
	};

	bus_table(const std::string&);

	void add_bus(bus);
	void remove_bus(ui);
	void show_table() const;
	void personal_task() const;

private:
	std::string fn;
	std::fstream f;
	std::vector<bus> buses;

	bus_buff buff;
	void send_into_file()
	{
		f.close();

		std::fstream ost;
		ost.open("new.txt", std::ios::out);
		

		for (int i(0); i < buses.size(); ++i)
		{
			ost << buses[i];
//			if (i != buses.size()) ost << '\n';
		}
/*
		for (auto it : buses)
		{
			ost << it;
		}*/
		
		ost.close();
		std::remove("buses_table.txt");
		std::rename("new.txt", "buses_table.txt");

		f.open(fn, std::ios::in | std::ios::out | std::ios::app);
	}
};

