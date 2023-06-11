#pragma once

#include "user.h"

class admin : public user  // класс администратора , который может корректировать доску с маршрутами. унаследован от user
{
public:
	admin(const std::string&);

	void add_bus();
	void remove_bus();
};

