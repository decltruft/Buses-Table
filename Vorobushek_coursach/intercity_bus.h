#pragma once

#include "bus.h"

class intercity_bus : public bus // ����� �������� ������������ ��������. ��������� ������ bus 
{
public:
	intercity_bus(ui, std::string, Time, Time, Type);
};

