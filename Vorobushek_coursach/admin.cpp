#include "admin.h"

admin::admin(const std::string &str) : user(str)	// конструктор класса администратора
{

}

void admin::add_bus()		// метод добавления нового рейса на доску
{
	bus_table::bus_buff buff;
	ui t, lt, at;

	std::cout << "Введите номер нового маршрута: ";
	std::cin >> buff.route_number;

	std::cout << "Выберите тип автобуса:\n1 - городской\n2 - межгородний\n3 - сельской местности\n";
	std::cin >> t;
	switch (t)
	{
		case 1: buff.type = bus::Type::City_Bus; break;
		case 2: buff.type = bus::Type::Intercity_Bus; break;
		case 3: buff.type = bus::Type::Shuttle_Bus; break;
		default: buff.type = bus::Type::Default; break;
	}

	std::cin.get();
	std::cout << "Введите название конечной остановки: ";
	getline(std::cin, buff.finished_stop);

	std::cin.get();
	std::cout << "Введите время отправки (формата 1815 - 18ч 15мин): ";
	std::cin >> lt;
	buff.time_to_leave = lt;

	while (std::cin.get() != '\n');
	std::cout << "Введите время прибытия (формата 1815 - 18ч 15мин): ";
	std::cin >> at;
	buff.arrival_time = at;

	(this->get_bt())->add_bus(bus(buff.route_number, buff.finished_stop, buff.time_to_leave, buff.arrival_time, buff.type));
	std::cout << "Маршрут с номером " << buff.route_number << " успешно создан!" << std::endl;
}

void admin::remove_bus()	// метод удаления существующего рейса с доски
{
	ui rn;
	std::cout << "Введите номер маршрута для удаления: ";
	std::cin >> rn;

	(this->get_bt())->remove_bus(rn);
}
