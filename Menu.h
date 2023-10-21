#pragma once
#include <iostream>
#include <fstream>
#include "Transport.h"
using namespace std;
class Menu {
protected:
	Transport* transports;
	string redact;
	int exit = 1;
public:
	void main_menu();
	int show_options();
};