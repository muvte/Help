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
		my_class () { //�����������
			cout << "������� ���, ������� � ��� ������������" << "\n";
			cin >> year >> sname >> fname;
		}
		~my_class()
		{
			cout << "�������";
		}
};

int main ()
{
	setlocale (0,"");
	
	my_class A;
	A.year=10;
	
}
