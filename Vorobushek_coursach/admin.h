#pragma once

#include "user.h"

class admin : public user  // ����� �������������� , ������� ����� �������������� ����� � ����������. ����������� �� user
{
public:
	admin(const std::string&);

	void add_bus();
	void remove_bus();
};

