#include "bus_table.h"

bus_table::bus_table(const std::string &filename) : fn(filename), f(filename, std::ios::in | std::ios::out | std::ios::app)		// ����������� ������ ���������� �������
{
	if (!(f.is_open()))
		throw bad_opened_file();

	ui t;
	ui lt, at;
	
	while (f >> buff.route_number >> t >> buff.finished_stop >> lt >> at)
	{
		buff.time_to_leave = lt;
		buff.arrival_time = at;

		switch (t)
		{
		case 0:
			buff.type = bus::Type::Default; break;
		case 1:
			buff.type = bus::Type::City_Bus; break;
		case 2:
			buff.type = bus::Type::Intercity_Bus; break;
		case 3:
			buff.type = bus::Type::Shuttle_Bus; break;
		default:
			buff.type = bus::Type::Default; break;
		}

		buses.push_back(bus(buff.route_number, buff.finished_stop, buff.time_to_leave, buff.arrival_time, buff.type));
	}
}

void bus_table::add_bus(bus b)		// ����� ���������� ������ �������� 
{
	f << b;
	buses.push_back(b);
}

void bus_table::remove_bus(ui rn)		// ����� �������� �������� �� �������
{
	for (std::vector<bus>::const_iterator it = buses.begin(); it != buses.end(); ++it)
	{
		if ((*it).route_number == rn)
		{
			buses.erase(it);
			std::cout << "������� � ������� " << rn << " ������� �����!" << std::endl;
			break;
		}
	}
	send_into_file();
}

void bus_table::show_table() const		// ����� ����������� ������� ���� ��������� ���������
{
	std::cout << "\t\t\t\t\t������ ���� ��������� ���������:\n\n\n";
	std::cout << "=======================================================================================================================" << std::endl;
	std::cout << "|\t����� �����:\t|\t��� ��������:\t|\t�������� ���������:\t|\t����� ��������\\����� ��������:\t|\n|\n";

	for (auto it : buses)
	{
		it.show_bus();
		std::cout << std::endl;
		std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	}
	std::cout << "=======================================================================================================================\n\n\n";
}

void bus_table::personal_task() const		// ����� ��� ����������� ��������������� ������� (������ � ���������)
{
	time_t now;
	tm nowLocal;

	now = time(NULL);
	localtime_s(&nowLocal, &now);

	while (std::cin.get() != '\n');

	std::string finished_stop;
	std::cout << "������� �������� ���������, �� ������� ������ ���������: ";
	std::getline(std::cin, finished_stop);

	std::cout << "������ ���������, �� ������� ����� ��������� �� " << finished_stop 
		      << " �� �������, ��� �� 12 ����� �� �������� �������: ";
	bool isInclude = false;

	for (auto it : buses)
	{
		if (it.finished_stop == finished_stop)
		{
			if (((it.arrival_time.get_h() - nowLocal.tm_hour <= 12) && (it.arrival_time.get_h() - nowLocal.tm_hour >= 0)) 
				|| (it.arrival_time.get_h() - nowLocal.tm_hour <= -12)) 
			{
				isInclude = true;
				std::cout << it.route_number << ' ';
			}
		}
	}
	if (!isInclude) std::cout << "����������� ������� �� ������!";
	std::cout << std::endl;
}
