#include <iostream>
using namespace std;
void massiv (int A[10])
{
	int i;
	for (i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
}
int main ()
{
	int A [10], i;
	for (i = 0; i < 10; i++) {
		cin >> A[i];
	}
	massiv (A);
}
