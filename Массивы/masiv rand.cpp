#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void massiv (int A[10])
{
	int i;
	srand (time(0));
	for (i = 0; i < 10; i ++) {
		A [i] = (rand() % 100);
	}
}
int main ()
{
	int A [10], i;
	massiv (A);
	for (i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
}
