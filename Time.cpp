#include "Time.h"
#include <iostream>
#include <windows.h>    // Библиотека для русской локализации
using namespace std;

//перегрузка операции присваивания 
Time& Time::operator=(const Time& m)
{
	//проверка на самоприсваивание 
	if (&m == this) return *this;
	min = m.min;
	sec = m.sec;
	return *this;
}

bool Time::operator <(const Time& t)
{
	if (min < t.min)return true;
	if (min == t.min && sec < t.sec)return true;
	return false;
}
bool Time::operator >(const Time& t)
{
	if (min > t.min)return true;
	if (min == t.min && sec > t.sec)return true;
	return false;
}
Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

Time Time::operator-(const Time& t)
{
	int temp1 = min * 60 - sec;
	int temp2 = t.min * 60 - t.sec;
	Time p;
	p.min = (temp1 - temp2) / 60;
	p.sec = (temp1 - temp2) % 60;
	return p;
}

//перегрузка бинарной операции деления
Time Time::operator/(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 / temp2) / 60;
	p.sec = (temp1 / temp2) % 60;
	return p;
}
Time Time::operator/(const int& t)
{
	int temp1 = min * 60 + sec;
	Time p;
	p.min = (temp1 / t) / 60;
	p.sec = (temp1 / t) % 60;
	return p;
}
bool Time::operator ==(const Time& t)
{
	if (min != t.min)return false;
	if (sec == t.sec) return true;
	return false;
}
//-------------------------------------------------------------
//перегрузка глобальной функции-операции ввода 
std::istream& operator >> (std::istream& in, Time& m)
{
	cout << "Vvedite kol-vo min: "; in >> m.min;
	cout << "Vvedite kol-vo sec: "; in >> m.sec;
	return in;
}
//-------------------------------------------------------------
//перегрузка глобальной функции-операции вывода 
std::ostream& operator << (std::ostream& out, const Time& m)
{
	return (out << m.min << ":" << m.sec);
}
//-------------------------------------------------------------