#include <iostream>
using namespace std;
int requr (int n, int k)
{
	int res;
	if (k == n or k == 0) {
		return 1;
	}	
	res = requr (n - 1, k - 1) + requr (n - 1, k);
	return res;
}
int main ()
{
	int n, k, res, d;
	cin >> n >> k;
	cout << requr (n,k);
}
