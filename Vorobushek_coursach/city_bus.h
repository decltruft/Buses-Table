#pragma once

#include "bus.h"

class city_bus : public bus			// ����� �������� ���������� ��������. ��������� ������ bud
{
public:
	city_bus(ui, std::string, Time, Time, Type);
};

