#include <iostream>
#include <fstream>
using namespace std;

struct str
{
	int year;
	string fname, sname;
	str *next;
	str *priv;
};

void vivod (str *top)
{
	int i, counter;
	counter = 1;
	ofstream text;
	text.open("Baza.txt");
	if (!text.is_open()) {
		cout << "�������!";
	}
	str *now = top;
	while (now != NULL) {
		cout << counter << "\t";
		cout << now->year << "\t";
		cout << now->fname << "\t";
		cout << now->sname << "\n";
		now = now->next;
		counter ++;
	}
	text.close();
}

str* zapol (str *top) {
	
	str *A = new str;
	cout << "������� ��� ��������" << "\n";
	cin >> A->year;
	cout << "������� ��� � ��������� �����" << "\n";
	cin >> A->fname;
	cout << "������� ������� � ��������� �����"  << "\n";
	cin >> A->sname;
	A->next = NULL;
	if (top == NULL) {
		A->priv = NULL;
		top = A;
		return top;
	} 
	str *now = top;
	while (now->next != NULL)
		now = now->next;
	now->next = A;
	A->priv = now;
}

str* nahozd (str *top) {
	setlocale (0,"");
	str *now = top;
	string fname2, sname2;
	int year2, counter2;
	str *ukaz; 
	cout << "������� ������� ������������ � ��������� �����" << "\n";
	cin >> sname2;
	counter2 = 0; // ������������ ������� � 0
	while (now->next != NULL) { // �������� ������� ����� � ����������� ��������
		if (now->sname == sname2) { // ���������� �������
			counter2++;
			ukaz = now;
		}
		now = now->next; //������������ � ��������� "������"
	}
	cout << "����� ������� " << counter2 << "�������� ������" << "\n";
	if (counter2 > 1) {
		cout << "������� ��� ������������ � ��������� �����" << "\n";
		cin >> fname2;
		counter2 = 0; // ������������ ������� � 0
		while (now->next != NULL) { // �������� ������� ����� � ����������� ������, ��������
			if (now->fname == fname2) { // ���������� �������
				counter2++;
				ukaz = now;
			}
			now = now->next; //������������ � ��������� "������"
		}
		cout << "����� ������� " << counter2 << "�������� ������" << "\n";
		if (counter2 > 1) {
			cout << "������� ��� �������� ������������" << "\n";
			cin >> year2;
			counter2 = 0; // ������������ ������� � 0
			while (now->next != NULL) { // �������� ������� ����� � ����������� ������, ��������, �����
				if (now->year == year2) { // ���������� �������
					counter2++;
					ukaz = now;
				}
				now = now->next; //������������ � ��������� "������"
			}
			if (counter2 > 1) {
				cout << "� �� ���� ������� �� ������ ���. ����� � ��������� �������� 'Baza' � ������� ��� ����������! :(" << "\n";
			} else {
				return ukaz;
			}
		} else {
			return ukaz;
		}
	} else {
		return ukaz;
	}
}

str* udal (str *c, str *top) {
	if (c->priv == NULL && c->next == NULL) {
		delete c;
		return NULL;
	}
	if (c->priv == NULL) {
		top = c->next;
		(c->next)->priv = NULL;
		delete c;
		return top;
	}
	if (c->next == NULL) {
		(c->priv)->next = NULL;
		delete c;
		return top;
	}
	(c->priv)->next = c->next;
	(c->next)->priv = c->priv;
	delete c;
	return top;
}

int main ()
{
	setlocale (0, "");
	int i, n, a, b, c;
	b = 1;
	str *top = NULL;
	str *X;
	while (b == 1) {
		cout << "������� �����." << "\n" << "1. ������ ������ ������������" << "\n";
		cout << "2. ������� ������������" << "\n" << "3. ����� ������������" << "\n" << "4. ������� ��� ���������" << "\n" << "5. ��������� ������" << "\n";
		cin >> a;
		switch (a) {
			case 1:
				top = zapol (top);
				break;
			case 2:
				X = nahozd (top);
				top = udal (X, top);
				break;
			case 3:
				X = nahozd (top);
				cout << X->year << "\t";
				cout << X->fname << "\t";
				cout << X->sname << "\n";
				break;
			case 4:
				vivod (top);
				break;
			case 5:
				b = 0;
				break;
		}
	}
}
