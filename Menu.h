#pragma once
#include <iostream>
#include <fstream>
#include "Keep.h"
#include "Transport.h"
using namespace std;
class Menu {
protected:
	Keep list;
	Transport* transports;
	string redact;
	int exit = 1;
public:
	void main_menu();
	int show_options();
	void show_all_transports();
	void change_data();
	void add_new();
	void save_to_file();
	void load_from_file();
	void delete_transport();
	void exit_from_programm();
};