#include "Time.h"

Time::Time(ui h, ui m)		// конструктор класса для работы со временем
{
	if (h > 23) h = 23;
	else if (h < 0) h = 0;

	hourse = h;

	if (m > 59) m = 59;
	else if (m < 0) m = 0;

	minutes = m;
}

void Time::show_time() const		// метод корректного отображения времени
{
	if (hourse < 10) std::cout << '0' << hourse << ':';
	else std::cout << hourse << ':';

	if (minutes < 10) std::cout << '0' << minutes;
	else std::cout << minutes;
}

fstream& operator>>(fstream& fs, Time& t)		// перегрузка оператора >> для корректной записи из файла времени в объект класса Time
{
	ui time;
	fs >> time;

	t.hourse = time / 100;
	t.minutes = time % 100;

	return fs;
}

Time& Time::operator=(ui time)		// перегрузка оператора = для корректного присваивания одного объекта класса Time другому объекту
{
	hourse = time / 100;
	minutes = time % 100;

	return *this;
}