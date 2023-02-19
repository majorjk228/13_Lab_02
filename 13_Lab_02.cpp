#include "Time.h" 
#include "deque" 
#include "queue" 
#include <iostream> 
#include <conio.h>
#include <algorithm> 
using namespace std;

typedef queue<Time>que;
typedef deque<Time>deq;

//формирование вектора 
que make_queue(int n)
{
	que s;
	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//ввод переменной 
		s.push(t);//добавление ее в стек 
	}
	return s;//вернуть стек как результат функции  
}

//копирует из одной очереди в другую
deq copy_queue_to_deque(que s)
{
	deq v;
	while (!s.empty())//пока не пустой  
	{
		//добавить в вектор элемент из вершиы стека  
		v.push_back(s.front());
		s.pop();
	}
	return v; //вернуть вектор как результат функции  
}
//копирует из одной очереди в другую
que copy_deque_to_queue(deq v)
{
	que s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//добавить в стек элемент вектора 
	}
	return s; //вернуть стек как результат функции  
}

//функция для печати
void print_queue(que s)
{
	std::cout << endl;
	deq v = copy_queue_to_deque(s);// копируем стек в вектор 
	while (!s.empty())
	{
		std::cout << s.front() << endl;
		s.pop();
	}
	s = copy_deque_to_queue(v);//скопировать вектор в стек  
	std::cout << endl;
}


Time s;

struct Greater_s //больше, чем s 
{
	bool operator()(Time t)
	{
		if (t > s) return true; else return false;
	}
};

struct Comp_less // для сортировки по убыванию 
{
public:
	bool operator()(Time t1, Time t2)
	{

		if (t1 > t2)return true;
		else return false;
	}
};


//вычисление среднего значения 
Time minmax(que s)
{
	deq v = copy_queue_to_deque(s);// копируем стек в вектор 
	deq::iterator x;
	x = min_element(v.begin(), v.end());
	std::cout << "min=" << *(x) << endl;
	Time g = *(x);

	deq::iterator y;
	y = max_element(v.begin(), v.end());
	std::cout << "max=" << *(y) << endl;
	Time h = *(y);
	Time p = h + g;
	std::cout << "min+max=" << p << endl;
	return p;
}

struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};

void del(Time& t)
{
	t = t + s;
}


void main()
{
	int n;
	cout << "kolvo elementov: ";
	cin >> n;
	que v;
	v = make_queue(n);
	print_queue(v);
	deq vv;
	deq::iterator i;
	//поставили итератор i на минимальный элемент 

	vv = copy_queue_to_deque(v);
	i = min_element(vv.begin(), vv.end());
	cout << "min=" << *(i) << endl;
	Time m = *(i);
	vv.push_back(m);
	v = copy_deque_to_queue(vv);
	print_queue(v);


	cin >> s;
	//поиск элементов, удовлетворяющих условию предиката  
	i = find_if(vv.begin(), vv.end(), Equal_s());
	if (i != vv.end())//если нет конца вектора 
	{
		cout << "Element nomer:" << *(i) << endl << "Udalenie" << endl;
		s = *i;
		//переместили элемент
		i = remove_if(vv.begin(), vv.end(), Equal_s());
		//удалили элементы, начиная с i и до конца вектора  
		vv.erase(i, vv.end());
		v = copy_deque_to_queue(vv);
		print_queue(v);
	}
	else
		cout << "Not such element!" << endl;

	cout << "pribavlenie" << endl;
	s = minmax(v);//нашли среднее арифметическое вектора 
	//для каждого элемента вектора вызывается функция del 
	for_each(vv.begin(), vv.end(), del);
	v = copy_deque_to_queue(vv);
	print_queue(v);

	_getch();
}