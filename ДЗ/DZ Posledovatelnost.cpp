#include <iostream>
using namespace std;
double Summ (int a, int m, int k) 
{
	int i;
	double b;
	int A[k];
	A[0] = a;
	b = a;
	for (i = 1; i < k; i++) {
		A[i] = m / A[i - 1];
		b = b + A[i];
	}
	return b;
}
int main ()
{
	int a, m, k, b;
	cin >> a >> m >> k;
	b = Summ (a, m, k);
	cout << b;
}


