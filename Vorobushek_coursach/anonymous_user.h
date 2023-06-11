#pragma once

#include "user.h"

class anonymous_user : public user		// класс анонимного пользователя, который просматривает доску без возможности внести поправки в нее. унаследован от user
{
public:
	anonymous_user(const std::string&);
};

