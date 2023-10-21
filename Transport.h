#pragma once
using namespace std;
class Transport {
public:
	Transport() {};
	virtual ~Transport() {};

	virtual void show() = 0;
	virtual void rewrite() = 0;
	virtual void saving() = 0;
	virtual void redact_str(int num_str, string red_str) = 0;
	virtual bool avermark(double a) = 0;
};
typedef struct El 
{
	Transport* data;
	El* next;
} El;
