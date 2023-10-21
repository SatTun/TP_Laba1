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
	cout << "\nКакое действие выполнить?"<< endl;
	cout << "1 - Показать весь транспорт" << endl;
	cout << "2 - Изменить данные о транспорте" << endl;
	cout << "3 - Добавить новый транспорт" << endl;
	cout << "4 - Сохранить все изменения в файле" << endl;
	cout << "5 - Загрузить из файла данные о транспорте" << endl;
	cout << "6 - Удалить транспорт" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "-> ";
	cin >> c1;
	return c1;
}