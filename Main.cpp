#include <iostream>
#include <locale>
#include <Windows.h>
#include "Menu.h"
using namespace std;
// ����� ����� ������ ������ �� �����������, ���������� � ���������. ��� 
// ������� ���������� ���������� : �����, ������, ����� ���������, ����, ���
// ���.��� ������� ��������� ���������� : �����, ������, ����� ���������,
// �������� ���������, ��� ����� ��������� �������� ������������.���
// ������� �������� ���������� : �����, ������, ���������� �������
// ������������ ����, ����� ���������� ������������ ����, �������� �����.
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	Menu menu;
	menu.main_menu();
	return 0;
}