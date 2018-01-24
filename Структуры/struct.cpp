#include <iostream>include <fstream>
#include <cstring>
using namespace std;
struct A {
	string sname;
	string fname;
	int age;
	string office;
	string job;
	int tel;
	int date;
	int salary;
};

int B (int *A, int n) 
{
	int i;
	ifstream my_file;
	my_file.open("data.txt");
	if (!my_file.is_open()) {
		cout << "404";
	}
	for (i = 0; i < n; i++) {
		my_file >> A[i].sname;
		my_file >> A[i].fname;
		my_file >> A[i].sex;
		my_file >> A[i].office;
		my_file >> A[i].job;
		my_file >> A[i].tel;
		my_file >> A[i].date;
		my_file >> A[i].salary;}
	my_file.close();
}

int C (int *A, int n) 
{
	int i;
	for (i = 0; i < n; i++) {
		A[i].date
	}	
}

int main()
{
	int sruct A[n];
	int i, n;
	cin << n;
	int A[n];
	chit (A, n)
}
