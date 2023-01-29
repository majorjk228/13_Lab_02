#include "Money.h" 
#include <iostream> 
using namespace std;

//------------------------------------------------------------- 
//���������� �������� ������������ 
Money& Money::operator=(const Money& m)
{
	//�������� �� ���������������� 
	if (&m == this) return *this;
	rub = m.rub;
	kop = m.kop;
	return *this;
}
//-------------------------------------------------------------
//���������� �������� �������� �������

Money Money::operator/(const Money& m)
{
	double temp1 = rub * 100 + kop;
	double temp2 = m.rub * 100 + m.kop;
	Money p;
	p.rub = int(temp1 / temp2);
	p.kop = int(temp1 / temp2) % 100;
	return p;
}

Money Money::operator/(const int& t)
{
	int temp1 = rub * 100 + kop;

	Money p;
	p.rub = (temp1 / t) / 100;
	p.kop = (temp1 / t) % 100;
	return p;
}
//-------------------------------------------------------------
//���������� �������� �������� ��������� ����� �� ������� ����� 
Money Money::operator * (const Money& m)
{
	int temp1 = rub * 100 + kop;
	double temp2;
	cout << "Vvedite chislo v formate 'celoe.drobnoe': " << endl;
	cin >> temp2;
	Money p;
	p.rub = (temp1 * temp2) / 100;
	p.kop = int(temp1 * temp2) % 100;
	return p;
}

//-------------------------------------------------------------
//���������� ���������� �������-�������� ����� 
std::istream& operator >> (std::istream& in, Money& m)
{
	cout << "Vvedite kol-vo rublei: "; in >> m.rub;
	cout << "Vvedite kol-vo kopeek: "; in >> m.kop;
	return in;
}
//-------------------------------------------------------------
//���������� ���������� �������-�������� ������ 
std::ostream& operator << (std::ostream& out, const Money& m)
{
	return (out << m.rub << "," << m.kop);
}
//-------------------------------------------------------------
//���������� �������� ���������
bool Money::operator >(const Money& t)
{
	if (rub > t.rub)return true;
	if (rub == t.rub && kop > t.kop)return true;
	return false;
}

bool Money::operator <(const Money& t)
{
	if (rub < t.rub)return true;
	if (rub == t.rub && kop < t.kop)return true;
	return false;
}

bool Money::operator ==(const Money& t)
{
	if (rub != t.rub)return false;
	if (kop == t.kop) return true;
	return false;
}
//-------------------------------------------------------------
//���������� �������� ��������
Money Money::operator + (const Money& m)
{
	int temp1 = rub * 100 + kop;
	int temp2 = m.rub * 100 + m.kop;
	Money p;
	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;
	return p;
}