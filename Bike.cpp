#include <iostream>
#include <fstream>
#include <string>
#include "Bike.h"
using namespace std;

Bike::Bike()
{
	cout << "Конструктор без аттрибутов" << endl;
}
Bike::~Bike()
{
	cout << "Деструктор" << endl;
}
Bike::Bike(const Bike& Bike_copy)
{
	stamp = Bike_copy.stamp;
	mark = Bike_copy.mark;
	engineVol = Bike_copy.engineVol;
	enginePower = Bike_copy.enginePower;
	locale = Bike_copy.locale;

	cout << "Конструктор осуществлен успешно" << endl;
}
Bike::Bike(string stamp)
{
	this->stamp = stamp;
	cout << "Конструтор Bike с атрибутами" << endl;
}
string Bike::get_stamp() const
{
	return stamp;
}
void Bike::set_stamp(string stamp_ch)
{
	stamp = stamp_ch;
}
string Bike::get_mark() const
{
	return mark;
}
void Bike::set_mark(string mark_ch)
{
	mark = mark_ch;
}
string Bike::get_engineVol() const
{
	return engineVol;
}
void Bike::set_engineVol(string engineVol_ch)
{
	engineVol = engineVol_ch;
}
string Bike::get_enginePower() const
{
	return enginePower;
}
void Bike::set_enginePower(string enginePower_ch)
{
	enginePower = enginePower_ch;
}
string Bike::get_locale() const
{
	return locale;
}
void Bike::set_locale(string locale_ch)
{
	locale = locale_ch;
}
void Bike::show()
{
	cout << "------------------------------------" << endl;
	cout << "Транспорт: Bike" << endl;
	cout << "Модель(Stamp): " << stamp << endl;
	cout << "Марка(Mark): " << mark << endl;
	cout << "Объем двигателя(EngineVol): " << engineVol << endl;
	cout << "Мощность двигателя(EnginePower): " << enginePower << endl;
	cout << "Местность(Locale): " << locale << endl;
	cout << "------------------------------------" << endl;
}
void Bike::rewrite()
{
	cout << "------------------------------------" << endl;
	cout << "Bike: " << endl;
	cout << "Введите модель: ";
	getline(cin, stamp);
	getline(cin, stamp);
	cout << "Введите марку: ";
	getline(cin, mark);
	cout << "Введите объем двигателя: ";
	getline(cin, engineVol);
	cout << "Введите мощность двигателя: ";
	getline(cin, enginePower);
	cout << "Введите местность, по которой мотоцик предназначен: ";
	getline(cin, locale);

	cout << "------------------------------------" << endl;
}
void Bike::saving()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		exit(1);
	}
	else
	{
		outfile << 2 << endl << stamp << endl << mark << endl << engineVol << endl << enginePower << endl << locale << endl;
		outfile.close();
	}
}
void Bike::redact_str(int num_str, string red_str)
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
		this->engineVol = red_str;
		break;
	case 4:
		this->enginePower = red_str;
		break;
	case 5:
		this->locale = red_str;
		break;
	default:
		cout << "Неправильный ввод" << endl;
		break;
	}
}
