#include <iostream>
#include <locale>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Menu.h"

using namespace std;

void Menu::main_menu()
{
	while (exit == 1)
	{
		switch (show_options())
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			break;
			
		default:
			
			break;
		}
	}
}
int Menu::show_options() {
	int c1;
	cout << "\n����� �������� ���������?"<< endl;
	cout << "1 - �������� ���� ���������" << endl;
	cout << "2 - �������� ������ � ����������" << endl;
	cout << "3 - �������� ����� ���������" << endl;
	cout << "4 - ��������� ��� ��������� � �����" << endl;
	cout << "5 - ��������� �� ����� ������ � ����������" << endl;
	cout << "6 - ������� ���������" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "-> ";
	cin >> c1;
	return c1;
}