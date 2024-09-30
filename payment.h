#pragma once
#include<iostream>

#include<fstream>
using namespace std;


class payment
{
public:
	payment();
	~payment();
	virtual void pay() = 0;
	

private:

};

payment::payment()
{

}

payment::~payment()
{
}
class JazzCash : public payment
{
public:
	JazzCash();
	~JazzCash();
	void pay()
	{
		
		cout << " Payment is being proccess through Jazz Cash!" << "Payment Done" << endl;
		cout << "Give Feedback" << endl;



	}

private:

};

JazzCash::JazzCash()
{
}

JazzCash::~JazzCash()
{
}

class EasyPaisa : public payment
{
public:
	EasyPaisa();
	~EasyPaisa();
	void pay()
	{
		
		cout << " Payment is being proccess through EasyPaisa!" << "Payment Done" << endl;
		cout << "Give Feedback" << endl;


	}

private:

};

EasyPaisa::EasyPaisa()
{
}

EasyPaisa::~EasyPaisa()
{
}
class UnionPay : public payment
{
public:
	UnionPay();
	~UnionPay();
	void pay()
	{
		cout << " Payment is being proccess through UnionPay!" << "Payment Done" << endl;
		cout << "Give Feedback" << endl;


	}

private:

};

UnionPay::UnionPay()
{
}

UnionPay::~UnionPay()
{
}
class PakPay : public payment
{
public:
	PakPay();
	~PakPay();
	void pay()
	{
		
		cout << " Payment is being proccess through PakPay!" << "Payment Done" << endl;
		cout << "Give Feedback" << endl;

	}
private:

};

PakPay::PakPay()
{
}

PakPay::~PakPay()
{
}

