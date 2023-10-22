#include <iostream>
#include <fstream>
#include <string>
#include "Bike.h"
using namespace std;

Bike::Bike()
{
	cout << "����������� ��� ����������" << endl;
}
Bike::~Bike()
{
	cout << "����������" << endl;
}
Bike::Bike(const Bike& Bike_copy)
{
	stamp = Bike_copy.stamp;
	mark = Bike_copy.mark;
	engineVol = Bike_copy.engineVol;
	enginePower = Bike_copy.enginePower;
	locale = Bike_copy.locale;

	cout << "����������� ����������� �������" << endl;
}
Bike::Bike(string stamp)
{
	this->stamp = stamp;
	cout << "���������� Bike � ����������" << endl;
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
	cout << "���������: Bike" << endl;
	cout << "������(Stamp): " << stamp << endl;
	cout << "�����(Mark): " << mark << endl;
	cout << "����� ���������(EngineVol): " << engineVol << endl;
	cout << "�������� ���������(EnginePower): " << enginePower << endl;
	cout << "���������(Locale): " << locale << endl;
	cout << "------------------------------------" << endl;
}
void Bike::rewrite()
{
	cout << "------------------------------------" << endl;
	cout << "Bike: " << endl;
	cout << "������� ������: ";
	getline(cin, stamp);
	getline(cin, stamp);
	cout << "������� �����: ";
	getline(cin, mark);
	cout << "������� ����� ���������: ";
	getline(cin, engineVol);
	cout << "������� �������� ���������: ";
	getline(cin, enginePower);
	cout << "������� ���������, �� ������� ������� ������������: ";
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
		cout << "������ �������� �����!" << endl;
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
		cout << "������������ ����" << endl;
		break;
	}
}
