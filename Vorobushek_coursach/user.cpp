#include "user.h"

user::user(const std::string &str) : bt(str)	// ����������� ������ ������������, ���������� ������� ��� ������ �������������� � ���������� ������������
{

}

void user::show() const			// �����-������ ��� ������ ������ ������ bus_table ��� ����������� ������� ���������
{
	bt.show_table();
}

bus_table* user::get_bt()		// ����� �������� ��������� �� ������� ���������
{
	return &bt;
}

void user::personal_task()		// �����-����� ��� ������ ������ ������ bus_table ��� ������ � �������������� �������� �������� ���������� � ���������
{
	bt.personal_task();
}