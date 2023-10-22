#include <iostream>
#include <locale>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Keep.h"
#include "Car.h"
#include "Bike.h"
#include "Bus.h"
using namespace std;
Keep::Keep() : size(0), head(nullptr) {}
Keep::Keep(int size) : head(nullptr)
{
	this->size = size;
}
Keep::~Keep()
{
	if (head != NULL)
	{
		El* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Transport();
			delete(buffer);
		}
		head->data->~Transport();
		delete(head);
	}
}
Transport* Keep::operator[] (const int id)
{
	if ((id >= size) || id < 0)
	{
		cout << "Неправильный индекс!" << endl;
		exit(1);
	}
	else
	{
		El* buffer = head;
		for (int i = 0; i < size - id - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->data);
	}
}
int Keep::get_size()
{
	return size;
}
void Keep::insert(Transport* new_data)
{
	El* tmp;
	tmp = new El;
	if (size == 0)
	{
		tmp->data = new_data;
		tmp->next = 0;
		++size;
	}
	else
	{
		tmp->data = new_data;
		tmp->next = head;
		++size;
	}
	head = tmp;
}
void Keep::remove(int id)
{
	if ((head != NULL) && (id < size) && (id >= 0))
	{
		El* temp = head, * temp2 = head;
		for (int i = 0; i < id; i++)
		{
			temp2 = temp;
			temp = temp->next;
		}
		if (temp == head)
		{
			head = temp->next;
		}
		else
		{
			temp2->next = temp->next;
		}
		temp->data->~Transport();
		delete(temp);
		size--;
	}
}
void Keep::save()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile.is_open())
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	else
	{
		outfile << size << endl;
		outfile.close();
	}
	El* buffer = head;
	for (int i = 0; i < size; i++)
	{
		buffer->data->saving();
		buffer = buffer->next;
	}
}
void Keep::load() {
	if (size != 0)
	{
		El* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Transport();
			delete(buffer);
		}
		head->data->~Transport();
		delete(head);
	}
	ifstream infile;
	int read_size, num_transport;
	string a, b, c, d, e;
	string initfile = "data.txt";
	Transport* transports;
	infile.open(initfile);
	if (!infile.is_open())
	{
		cout << "Error opening!" << endl;
		exit(1);
	}
	infile >> read_size;
	for (int i = 0; i < read_size; i++)
	{
		infile >> num_transport;
		infile.ignore(32767, '\n');
		if (num_transport == 1)
		{
			//infile >> a >> b >> c >> d >> e;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Car* car;
			car = new Car;
			car->set_stamp(a);
			car->set_engineVol(b);
			car->set_color(c);
			car->set_typeKPP(d);
			car->set_mark(e);
			transports = car;
			insert(transports);
		}
		if (num_transport == 2)
		{
			//infile >> a >> b >> c >> d >> e;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Bike* bike;
			bike = new Bike;
			bike->set_stamp(a);
			bike->set_mark(b);
			bike->set_engineVol(c);
			bike->set_enginePower(d);
			bike->set_locale(e);
			transports = bike;
			insert(transports);
		}
		if (num_transport == 3)
		{
			//infile >> a >> b >> c >> d >> e;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Bus* bus;
			bus = new Bus;
			bus->set_stamp(a);
			bus->set_mark(b);
			bus->set_number_seats(c);
			bus->set_number_passengers(d);
			bus->set_terminal_st(e);
			transports = bus;
			insert(transports);
		}
	}
}
