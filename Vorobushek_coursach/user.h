#pragma once

#include "bus_table.h"

#include <iostream>
#include <ctime>

using std::endl;
using std::cout;

class user          // ����� ������������ - ��������� ����� �������� ������ ��������� � ���������� ������������
{
public:
	user(const std::string&);
	virtual void show() const;
	bus_table* get_bt();
    void personal_task();

private:
	bus_table bt;
};

inline void show_head()         // ������� ������ "�����" ��������� � ��-���� � ������������ , ������������, � ������� ������� � �.�.
{
    time_t now;
    tm nowLocal;

    now = time(NULL);
    localtime_s(&nowLocal, &now);

    cout << "=======================================================================================================================" << endl;
    cout << "\t\t\t\t\t      " << nowLocal.tm_mday << '.' << nowLocal.tm_mon + 1 << '.' << nowLocal.tm_year + 1900 << endl;
    cout << "\t\t\t\t\t\t" << nowLocal.tm_hour << ':' << nowLocal.tm_min << endl;
    cout << "=======================================================================================================================\n";
    cout << "\t\t\t\t�����������: ��������� ������ ����������, ��. ��-061\n\t\t\t\t\t������������: �������� ����� ��������\n\t\t\t\t\t\t� 2022" << endl;
    cout << "=======================================================================================================================\n\n\n";
}

