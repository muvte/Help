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
		cout << "Подумай!";
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
	cout << "Введите год рождения" << "\n";
	cin >> A->year;
	cout << "Введите имя с заглавной буквы" << "\n";
	cin >> A->fname;
	cout << "Введите фамилию с заглавной буквы"  << "\n";
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
	cout << "Введите фамилию пользователя с заглавной буквы" << "\n";
	cin >> sname2;
	counter2 = 0; // Приравниваем счетчик к 0
	while (now->next != NULL) { // Проверям сколько людей с одинаковыми фамилией
		if (now->sname == sname2) { // сравниваем фамилии
			counter2++;
			ukaz = now;
		}
		now = now->next; //Перемещаемся в следующую "ячейку"
	}
	cout << "Таких найдено " << counter2 << "Уточните данные" << "\n";
	if (counter2 > 1) {
		cout << "Введите имя пользователя с заглавной буквы" << "\n";
		cin >> fname2;
		counter2 = 0; // Приравниваем счетчик к 0
		while (now->next != NULL) { // Проверям сколько людей с одинаковыми именем, фамилией
			if (now->fname == fname2) { // сравниваем фамилии
				counter2++;
				ukaz = now;
			}
			now = now->next; //Перемещаемся в следующую "ячейку"
		}
		cout << "Таких найдено " << counter2 << "Уточните данные" << "\n";
		if (counter2 > 1) {
			cout << "Введите год рождения пользователя" << "\n";
			cin >> year2;
			counter2 = 0; // Приравниваем счетчик к 0
			while (now->next != NULL) { // Проверям сколько людей с одинаковыми именем, фамилией, годом
				if (now->year == year2) { // сравниваем фамилии
					counter2++;
					ukaz = now;
				}
				now = now->next; //Перемещаемся в следующую "ячейку"
			}
			if (counter2 > 1) {
				cout << "Я не могу выбрать из полных тёск. Войди в текстовый документ 'Baza' и пофикси где напортачил! :(" << "\n";
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
		cout << "Введите цифру." << "\n" << "1. Ввести нового пользователя" << "\n";
		cout << "2. Удалить пользователя" << "\n" << "3. Найти пользователя" << "\n" << "4. Вывести всю структуру" << "\n" << "5. Закончить работу" << "\n";
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
