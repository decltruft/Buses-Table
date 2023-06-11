#include "bus.h"

bus::bus(ui rn, std::string fs, Time ttl, Time at, Type t = Type::Default)      // конструктор класса автобуса
    :route_number(rn), type(t), finished_stop(fs), 
     time_to_leave(ttl), arrival_time(at)
{

}

void bus::show_bus() const      // метод отображения маршрута автобуса в консоли
{   
    std::cout << "|  " << route_number << "\t\t\t|  "; 
    switch (type)
    {
    case Type::City_Bus: std::cout << "Городской\t\t"; break;
    case Type::Intercity_Bus: std::cout << "Межгородний\t\t"; break;
    case Type::Shuttle_Bus: std::cout << "Пригородный\t\t"; break;
    default: std::cout << "not defined"; break;
    }
    
    std::cout << "| " << finished_stop;

    if (finished_stop.size() < 29)
    {
        for (int i(0); i <= 29 - finished_stop.size(); ++i)
            std::cout << ' ';
    }

        std::cout << "|\t\t";
    time_to_leave.show_time();
    std::cout << '\\';
    arrival_time.show_time();
    std::cout << std::endl;
    std::cout << "|  ";

}

fstream& operator<<(fstream& fs, const bus& b)      // перегрузка оператора << для корректного ввода маршрута в файл через fstream
{
    fs << b.route_number << ' ' << static_cast<int>(b.type) << ' ' << b.finished_stop << ' '
        << b.time_to_leave.get_h() << b.time_to_leave.get_m() << ' ' 
        << b.arrival_time.get_h() << b.arrival_time.get_m() << '\n';

    return fs;
}
