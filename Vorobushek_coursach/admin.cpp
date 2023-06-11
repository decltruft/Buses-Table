#include "admin.h"

admin::admin(const std::string &str) : user(str)	// ����������� ������ ��������������
{

}

void admin::add_bus()		// ����� ���������� ������ ����� �� �����
{
	bus_table::bus_buff buff;
	ui t, lt, at;

	std::cout << "������� ����� ������ ��������: ";
	std::cin >> buff.route_number;

	std::cout << "�������� ��� ��������:\n1 - ���������\n2 - �����������\n3 - �������� ���������\n";
	std::cin >> t;
	switch (t)
	{
		case 1: buff.type = bus::Type::City_Bus; break;
		case 2: buff.type = bus::Type::Intercity_Bus; break;
		case 3: buff.type = bus::Type::Shuttle_Bus; break;
		default: buff.type = bus::Type::Default; break;
	}

	std::cin.get();
	std::cout << "������� �������� �������� ���������: ";
	getline(std::cin, buff.finished_stop);

	std::cin.get();
	std::cout << "������� ����� �������� (������� 1815 - 18� 15���): ";
	std::cin >> lt;
	buff.time_to_leave = lt;

	while (std::cin.get() != '\n');
	std::cout << "������� ����� �������� (������� 1815 - 18� 15���): ";
	std::cin >> at;
	buff.arrival_time = at;

	(this->get_bt())->add_bus(bus(buff.route_number, buff.finished_stop, buff.time_to_leave, buff.arrival_time, buff.type));
	std::cout << "������� � ������� " << buff.route_number << " ������� ������!" << std::endl;
}

void admin::remove_bus()	// ����� �������� ������������� ����� � �����
{
	ui rn;
	std::cout << "������� ����� �������� ��� ��������: ";
	std::cin >> rn;

	(this->get_bt())->remove_bus(rn);
}
