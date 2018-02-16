#include <iostream>
#include <cstring>
using namespace std;

class my_class {
	private:
		int year;
		string fname, sname; 
	public:
		string getfname ()
		{
			return fname;
		}
		string getsname ()
		{
			return sname;
		}
		int getyear ()
		{
			return year;
		}
		my_class () { //Конструктор
			cout << "Введите год, фамилию и имя пользователя" << "\n";
			cin >> year >> sname >> fname;
		}
		~my_class()
		{
			cout << "Удалено";
		}
};

int main ()
{
	setlocale (0,"");
	
	my_class A;
	A.year=10;
	
}
