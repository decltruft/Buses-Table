#pragma once

#include <iostream>
#include <exception>

using std::exception;

class bad_opened_file : public exception		// класс-исключение. бросается при некорректном имени файла. унаследован от std::exception
{
public:
	const char* what() const override
	{
		return "File was not opened: it does not existe!";
	}
};

