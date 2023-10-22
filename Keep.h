#pragma once
#include "Transport.h"
using namespace std;
using namespace std;
class Keep {
private:
	int size = 0;
	El* head = NULL;
public:
	Keep();
	Keep(int size);
	~Keep();

	Transport* operator[] (int id);

	int get_size();
	void insert(Transport* new_data);
	void remove(int id);
	void save();
	void load();
};

