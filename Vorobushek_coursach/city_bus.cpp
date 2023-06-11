#include "city_bus.h"

city_bus::city_bus(ui rn, std::string fs, Time ttl, Time at, Type t = Type::City_Bus)   // конструктор класса городского автобуса
    : bus(rn, fs, ttl, at, t)
{
    
}
