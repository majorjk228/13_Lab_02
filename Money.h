#pragma once

#include <iostream> 
//using namespace std; 

class Money
{
	long rub;
	int kop;

public:

	Money() { rub = 0; kop = 0; };
	Money(long r, int k) { rub = r; kop = k; };
	Money(const Money& m) { rub = m.rub; kop = m.kop; };
	~Money() {};

	int get_rub() { return rub; }
	int get_kop() { return kop; }

	void set_rub(long r) { rub = r; }
	void set_kop(int k) { kop = k; }

	//перегруженные операции 
	Money& operator=(const Money&);
	Money operator/(const Money&);
	Money operator/(const int&);
	Money operator*(const Money&);
	Money operator+(const Money&);

	bool operator>(const Money&);
	bool operator<(const Money&);
	bool operator ==(const Money&);

	//глобальные функции ввода-вывода
	friend std::istream& operator >> (std::istream& in, Money& m);
	friend std::ostream& operator << (std::ostream& out, const Money& m);

};
