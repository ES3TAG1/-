#include <iostream>
#include <string>
using namespace std;

class Goods {
	string name;
	string date;
	int cost;
	int num;
	int id;
public:
	Goods(string _name, string _date, int _cost, int _num, int _id) {
		name = _name;
		date = _date;
		cost = _cost;
		num = _num;
		id = _id;
		cout << "Counstructor" << endl;
	}	
	Goods() {
		name = "Unkown";
		date = "0000-00-00";
		cost = 0;
		num = 0;
		id = 0;
		cout << "Default constructor" << endl;
	}
	Goods(Goods& _ob) {
		name = _ob.name;
		date = _ob.date;
		cost = _ob.cost;
		num = _ob.num;
		id = _ob.id;
		cout << "CopyCounstructor" << endl;
	}
	~Goods() {
		cout << "Destructor"<< endl;
	};

public:
	void Show() {
		cout<< endl << "Наименование товара: " << name << endl;
		cout << "Дата оформления товара: " << date << endl;
		cout << "Цена товара: " << cost << endl;
		cout << "Количество единиц товара: " << num << endl;
		cout << "Номер накладной: " << id << endl<<endl;
	}

	Goods operator=(Goods& _ob);

};

Goods tovar(Goods& _s) {
	return _s;
}

Goods Goods::operator=(Goods& _ob) {
	name = _ob.name;
	date = _ob.date;
	cost = _ob.cost;
	num = _ob.num;
	id = _ob.id;
	cout << "Operator" << endl;
	return *this;
}


int main() {
	Goods watch1("Apple Watch", "21.03.2021", 10000, 300, 863);
	Goods watch2(watch1);
	Goods watch3;
	tovar(watch2);
	watch1 = watch3;
	watch1.Show();
	watch2.Show();
	return 0;
}