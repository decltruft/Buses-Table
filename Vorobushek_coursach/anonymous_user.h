#pragma once

#include "user.h"

class anonymous_user : public user		// ����� ���������� ������������, ������� ������������� ����� ��� ����������� ������ �������� � ���. ����������� �� user
{
public:
	anonymous_user(const std::string&);
};

