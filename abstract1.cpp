#include<iostream>
using namespace std;

class convert
{
	protected:
	
	double val1;	//initial value
	double val2;	//converted value
	public:

	convert(double i)
	{
		val1 = i;
	}
	
	double getcon()
	{
		return val2;
	}
	double getinit()
	{
		return val1;
	}
	
	virtual void compute() = 0;
};

//liters to gallons

class l_to_g:public convert
{
	public:
	
	l_to_g(double i): convert(i)
	{

	}

	void compute()
	{
		val2 = val1 / 3.7854;
	}
	
};

//fahrenheit to celsius

class f_to_c:public convert
{
	public:
	
	f_to_c(double i): convert(i)
	{
	
	}
	void compute()
	{
		val2 = (val1 - 32) / 1.8;
	}
};


int main()
{
	convert *p; //pointer to base class
	l_to_g lgob(4);
	f_to_c fcob(70);
	
	//use virtual function mechanism to convert
	
	p = &lgob;
	cout<<p->getinit()<<"liters is";
	p->compute(); 
	cout<<p->getconv()<<"gallons"<<endl; //l_to_g;
	p = &fcob();
	cout<<p->getinit<<"in fahrenheit is";
	p->compute();
	cout<<p->getconv()<<"celcius"<<endl; //f_to_c;
	return 0;
}
