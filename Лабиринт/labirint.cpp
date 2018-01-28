#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
int rand (int a, int b, int **A)
{
	srand (time (0));
	int i, j;
	for (i = 0; i < a + 2; i++) {
		for (j = 0; j < b + 2; j++) {
			if (i == 0 or j == b + 1 or i == a + 1 or j == 0) {
				A[i][j] = 1;
			} else {
				A[i][j] = rand()%2;
			}
		}
	}
}
int schitat (int a, int b, int **A)
{
	int i, j;
	setlocale (0, "");
	ifstream my_file;
	my_file.open("test.txt");
	if (!my_file.is_open())
	cout << "Не нашел файл :(";
	for (i = 0; i < a + 2; i++) {
		for (j = 0; j < b + 2; j++) {
			if (i == 0 or j == b + 1 or i == a + 1 or j == 0) {
				A[i][j] = 1;
			} else {
				my_file >> A[i][j];
			}
		}
	}
}
int scan (int c, int d, int **A, int a, int b)
{
	int i, j;
	i = c;
	j = d;
	if (A[i][j] == 3) {
		return 1;
	} else {
		if (A[i + 1][j] == 0) {
			A[i][j] = 2;
			if (scan (c + 1, d, A, a, b) == 1) {
				return 1'''';	
			}
		}
		if (A[i - 1][j] == 0) {
			A[i][j] = 2;
			if (scan (c - 1, d, A, a, b) == 1) {
				return 1;
			}
		}
		if (A[i][j + 1] == 0) {
			A[i][j] = 2;
			if (scan (c, d + 1, A, a, b) == 1) {
				return 1;
			}
		}
		if (A[i][j - 1] == 0) {
			A[i][j] = 2;
			if (scan (c, d - 1, A, a, b)) {
				return 1;
			}
		}
	}
	return 0;
}
int main ()
{
	setlocale (0, "");
	int a, b, i, j, c, d;
	cout << "Выберете: лабиринт будет задаваться рандомно (0) или вы зададите его сами (1)" << endl;
	cin >> d;
	cout << "Введите размер лабиринта" << endl;
	cin >> a >> b;
	int **A;
	A = new int * [a + 2];
	for (j = 0; j < a + 2; j++)
		A[j] = new int [b + 2];
	if (d == 0) {
		rand (a, b, A);
	} 
	if (d == 1) {
		schitat (a, b, A);
	}
	cout << "Введите начальное местоположение" << endl;
	cin >> c >> d;
	if (scan (c, d, A, a, b) == 1) {
		cout << "Робот дошел" << endl;
	} else {
		cout << "Робот не дошел" << endl;
	}
	for (i = 0; i < a + 2; i++) {
		for (j = 0; j < b + 2; j++) {
			cout << A[i][j];
		}
		cout << endl;
	}
}
