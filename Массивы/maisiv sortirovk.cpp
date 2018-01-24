#include <iostream>
using namespace std;
void massiv (int A[10])
{
	int i, j, s;
	int y [10];
	for (i = 0; i < 10; i++) { 
		s = 0; 
		for (j = 0; j < 10; j++) { 
			if (A[i] > A [j]) 
			s = s + 1; 
		} 
		y[s] = A[i]; 
	}
	for (i = 0; i < 10; i++) {
	A[i] = y[i]; 
	}
		
}
int main ()
{
	int A [10], i;
	i = 0;
	for (i = 0; i < 10; i++) {
		cin >> A[i];
	}
	massiv (A);
	for (i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
}

