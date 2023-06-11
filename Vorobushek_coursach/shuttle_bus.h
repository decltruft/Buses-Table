#pragma once

#include "bus.h"

class shuttle_bus : public bus				// класс описания автобуса сельской местности. наследник класса bus
{
public:
	shuttle_bus(ui, std::string, Time, Time, Type);
};

