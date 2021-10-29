#include <iostream>
using namespace std;

class Test {
protected:
	int W;
	void Z(){
		cout << "Это закрытая функция Test" << endl;
	}
public:
	Test() {
		W = 1;
	}
	~Test() {};

	friend void Fun(Test _ob);
};

void Fun(Test _ob) {
	cout << _ob.W << endl;
	_ob.Z();
}

int main() {
	Test ob;
	Fun(ob);

    return 0;
}