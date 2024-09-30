
#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include"../payment.h"
using namespace std;
class appointment
{
public:
	appointment();
	~appointment();
	void setDay(string d)
	{
		day = d;
	}
	string getDay() const {
		return day;
	}
	void setTime(string t)
	{
		time = t;
	}
	string getTime() const {
		return time;
	}
	void setcharges(int c)
	{
		charges = c;
	}
	int getCharges() const {
		return charges;
	}
	void TypeAppointment()
	{
		int a;
		cout << " Enter the type pf Appointment you like " << endl << "1. In-Person " << "2. Video appointment" << endl;
		cin >> a;
		
	}

	int show()
	{
		int b;

		cout << "Enter your Payment gate way:" << endl;
		cout << "1 for Jazz Cash" << endl;
		cout << "2 for Easy Paisaa" << endl;
		cout << "3 for Union Pay" << endl;
		cout << "4 for PakPay" << endl;

		cin >> b;
		return b;
	}

protected:
	string day;
	string time;
	int charges;

};

appointment::appointment()
{
	day = "";
	time = "";
	charges = 0;
}

appointment::~appointment()
{
}