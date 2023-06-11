#pragma once

#include "bus.h"

class city_bus : public bus			// класс описания городского автобуса. наследник класса bud
{
public:
	city_bus(ui, std::string, Time, Time, Type);
};

