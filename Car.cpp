#include <iostream>
#include <locale>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Car.h"
using namespace std;

Car::Car()
{
	cout << "Конструктор без аттрибутов" << endl;
}
Car::~Car()
{
	cout << "Деструктор" << endl;
}
Car::Car(const Car& Car_copy)
{
	stamp = Car_copy.stamp;
	mark = Car_copy.mark;
	engineVol = Car_copy.engineVol;
	color = Car_copy.color;
	typeKPP = Car_copy.typeKPP;

	cout << "Конструктор Car был вызван успешно" << endl;
}
Car::Car(string stamp)
{
	this->stamp = stamp;
	cout << "Конструтор Car с атрибутами" << endl;
}
string Car::get_stamp() const
{
	return stamp;
}
void Car::set_stamp(string stamp_ch)
{
	stamp = stamp_ch;
}
string Car::get_mark() const
{
	return mark;
}
void Car::set_mark(string mark_ch)
{
	mark = mark_ch;
}
string Car::get_engineVol() const
{
	return engineVol;
}
void Car::set_engineVol(string engineVol_ch)
{
	engineVol = engineVol_ch;
}
string Car::get_color() const
{
	return color;
}
void Car::set_color(string color_ch)
{
	color = color_ch;
}
string Car::get_typeKPP() const
{
	return typeKPP;
}
void Car::set_typeKPP(string course_ch)
{
	typeKPP = course_ch;
}

void Car::show()
{
	cout << "------------------------------------" << endl;
	cout << "Данный транспорт: Car" << endl;
	cout << "Модель(Stamp): " << stamp << endl;
	cout << "Марка(Mark): " << mark << endl;
	cout << "Объем двигателя(Engine Volume): " << engineVol << endl;
	cout << "Цвет(Color): " << color << endl;
	cout << "Тип КПП(TypeKPP): " << typeKPP << endl;

	cout << "------------------------------------" << endl;
}
void Car::rewrite()
{
	cout << "------------------------------------" << endl;
	cout << "Данный транспорт: Car" << endl;
	cout << "Введите новую марку: ";
	getline(cin, stamp);
	getline(cin, stamp);
	cout << "Введите новую марку: ";
	getline(cin, mark);
	cout << "Введите новый объем двигателя: ";
	getline(cin, engineVol);
	cout << "Введите новый цвет: ";
	getline(cin, color);
	cout << "Введите новый тип КПП: ";
	getline(cin, typeKPP);
	cout << "------------------------------------" << endl;
}
void Car::saving()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Ошибка открытия!" << endl;
		exit(1);
	}
	outfile << 1 << endl << stamp << endl << engineVol << endl << color << endl << typeKPP << endl << mark << endl;
	outfile.close();
}
void Car::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->stamp = red_str;
		break;
	case 2:
		this->mark = red_str;
		break;
	case 3:
		this->engineVol = red_str; this->color = red_str;
		break;
	case 4:
		this->color = red_str;
		break;
	case 5:
		this->typeKPP = red_str;
		break;
	default:
		throw "Неккоректный ввод данных!";
		break;
	}
}