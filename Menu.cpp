#include <iostream>
#include <locale>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Menu.h"
#include "Car.h"
#include "Bike.h"
#include "Bus.h"
using namespace std;

void Menu::main_menu()
{
	while (exit == 1)
	{
		switch (show_options())
		{
		case 1:
			show_all_transports();
			break;
		case 2:
			change_data();
			break;
		case 3:
			add_new();
			break;
		case 4:
			save_to_file();
			break;
		case 5:
			load_from_file();
			break;
		case 6:
			delete_transport();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}
int Menu::show_options() {
	int c1;
	cout << "\nКакое действие выполнить?" << endl;
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
void Menu::show_all_transports()
{
	try
	{
		if (list.get_size() == 0)
		{
			throw "Список транспортных средств пуст";
		}
		for (int i = 0; i < list.get_size(); i++)
		{
			cout << "_" << endl;
			cout << i + 1 << "|";
			list[i]->show();
		}
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::change_data()
{
	int c2, c3;
	try
	{
		cout << "Выберете транспорт, данные которого вы поменяете(от 1 до " << list.get_size() << ")?" <<
			endl;
		cin >> c2;
		if ((c2 < 1) || (c2 > list.get_size()))
		{
			throw "Неправильный ввод";
		}
		list[c2 - 1]->show();
		cout << "Какую строку вы будете менять(начиная с 0)?" << endl;
		cout << "-> ";
		cin >> c3;
		cin.ignore(32767, '\n');
		cout << "Введите изменения - " << endl;
		cout << "-> ";
		if (c3 == 5)
		{
			bool fl = false;
			while (fl == false)
			{
				try
				{
					getline(cin, redact);
					//float f = stof(redact);
					fl = true;
				}
				catch (...)
				{
					cout << "Введите номер" << endl;
				}
			}
			list[c2 - 1]->redact_str(c3, redact);
		}
		else
		{
			getline(cin, redact);
			list[c2 - 1]->redact_str(c3, redact);
			cout << "Строка была редактирована" << endl;
		}
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::add_new()
{
	int c2;
	cout << "\nКакой транспорт вы хотите добавить?" << endl;
	cout << "1 - Car" << endl;
	cout << "2 - Bike" << endl;
	cout << "3 - Bus" << endl;
	cout << "0 - Назад" << endl;
	cout << "-> ";
	cin >> c2;
	switch (c2)
	{
	case 1:
		Car * car;
		car = new Car;
		transports = car;
		car->rewrite();
		list.insert(transports);
		cout << "Новый автомобиль был добавлен." << endl;
		break;
	case 2:
		Bike * teacher;
		teacher = new Bike;
		transports = teacher;
		teacher->rewrite();
		list.insert(transports);
		cout << "Новый мотоцикл был добавлен." << endl;
		break;
	case 3:
		Bus * emp;
		emp = new Bus;
		transports = emp;
		emp->rewrite();
		list.insert(transports);
		cout << "Новый автобус был добавлен." << endl;
		break;
	default:
		break;
	}
}
void Menu::save_to_file()
{
	try
	{
		if (list.get_size() == 0)
		{
			throw "Здесь нечего сохранять";
		}
		list.save();
		cout << "Данные сохранены" << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::load_from_file()
{
	try
	{
		list.load();
		cout << "Данные загружены" << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::delete_transport()
{
	int c2;
	cout << "Какой траснспорт вы хотите удалить(от 1 до " << list.get_size() << ")?" << endl;
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << "_" << endl;
		cout << i + 1 << "|";
		list[i]->show();
	}
	cout << "-> ";
	cin >> c2;
	c2 = list.get_size() - c2 + 1;
	try {
		if ((c2 < 1) || (c2 > list.get_size()))
		{
			throw "Неправильный ввод";
		}
		list.remove(c2 - 1);
		cout << "Данный транспорт был удален" << endl;
	}
	catch (const char* i)
	{
		cout << i << endl;
	}

}
void Menu::exit_from_programm()
{
	exit = 0;
}