#pragma once
#include "Transport.h"
using namespace std;
class Bus : public Transport {
private:
	string stamp;
	string mark;
	string number_seats;
	string number_passengers;
	string terminal_st;
public:
	Bus();
	~Bus();
	Bus(const Bus& Bus_copy);
	Bus(string stamp);

	string get_stamp() const;
	void set_stamp(string name_ch);

	string get_mark() const;
	void set_mark(string mark_ch);

	string get_number_seats() const;
	void set_number_seats(string number_seats_ch);

	string get_number_passengers() const;
	void set_number_passengers(string number_passengers_ch);

	string get_terminal_st() const;
	void set_terminal_st(string terminal_st_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool avermark(double a) { return false; };
};
