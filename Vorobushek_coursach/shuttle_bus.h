#pragma once

#include "bus.h"

class shuttle_bus : public bus				// ����� �������� �������� �������� ���������. ��������� ������ bus
{
public:
	shuttle_bus(ui, std::string, Time, Time, Type);
};

