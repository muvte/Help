#include <iostream>
using namespace std;
int main ()
{
	setlocale (0, "");
	int a, b, c, i;
	cout << "������� ������ �������� ��� ����� ����� a � b ( a>0 , b<10^9 ). ��������� ������ �������� ���� ����� ����� - ���������� �������� �����, ������ �� ������� ����� ���� �������� ������������� ���� a, � ������ - ������������� ���� b." << endl;
	int A[10];
	int B[10];
	for(i = 0; i < 10; i++) {
		cin >> A[i];
	}
	for(i = 0; i < 10; i++) {
		cout << A[i];
	}
}
