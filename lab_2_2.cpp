#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;


class Abonent{
public:
	int id;
protected:
	string sName;
	string phoneNumber;
public:
	Abonent(int _id, string _sName, string _phoneNumber) {
		id = _id;
		sName = _sName;
		phoneNumber = _phoneNumber;
	}
	~Abonent() {};

	
	friend class Notebook;
};

class Notebook {

public:

	void change(Abonent& ob, string _newPhoneNumber) {
		ob.phoneNumber = _newPhoneNumber;
	}
	void show(Abonent& ob) {
		cout << ob.id << '|';
		cout << ob.sName << '|';
		cout << ob.phoneNumber << endl;
		cout << '\n';
	}
};

int main() {
	vector<Abonent> abonentArr;
	Notebook notebook;
	abonentArr.push_back(Abonent(1, "Илья", "89286131501"));
	abonentArr.push_back(Abonent(2, "Иван", "89184567182"));
	abonentArr.push_back(Abonent(3, "Дмитрий", "89184514444"));
	abonentArr.push_back(Abonent(4, "Игорь", "89184514444"));
	abonentArr.push_back(Abonent(5, "Денис", "89282968770"));
	for (int i = 0; i < abonentArr.size(); i++) {
		notebook.show(abonentArr[i]);
	}
	for (int i = 0; i < abonentArr.size(); i++) {
		if (abonentArr[i].id == 3) {
			notebook.change(abonentArr[i], "89990548400");
			break;
		}
	}
	cout << "------------------------------------" << endl;
	for (int i = 0; i < abonentArr.size(); i++) {
		notebook.show(abonentArr[i]);
	}
	return 0;
}