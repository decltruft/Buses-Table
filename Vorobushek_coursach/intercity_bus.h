#pragma once

#include "bus.h"

class intercity_bus : public bus // класс описания межгороднего автобуса. наследник класса bus 
{
public:
	intercity_bus(ui, std::string, Time, Time, Type);
};

