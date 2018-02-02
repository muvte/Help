#include <iostream>
#include <fstream>
#include <cstring>
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
		cout << "Ïîäóìàé!";
	}
	str *now = top;
	cout << "\t" << "\t" << "Ãîä" << "\t" << "Èìÿ" << "\t" << "Ôàìèëèÿ" << "\n";
	while (now != NULL) {
		cout << "\t" << counter << "\t";
		cout << now->year << "\t";
		cout << now->fname << "\t";
		cout << now->sname << "\n";
		now = now->next;
		counter ++;
	}
	text.close();
}

str* zapol (str *top) 
{
	
	str *A = new str;
	cout << "Ââåäèòå ãîä ðîæäåíèÿ" << "\n";
	cin >> A->year;
	cout << "Ââåäèòå èìÿ ñ çàãëàâíîé áóêâû" << "\n";
	cin >> A->fname;
	cout << "Ââåäèòå ôàìèëèþ ñ çàãëàâíîé áóêâû"  << "\n";
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
	now->next = A; // Íàäî âåðíóòü òîï íà ñâîå ìåñòî!!!
	A->priv = now;
	return top;
}

str* nahozd (str *top) 
{
	setlocale (0,"");
	str *now = top;
	string fname2, sname2;
	int year2, counter2;
	str *ukaz; 
	cout << "Ââåäèòå ôàìèëèþ ïîëüçîâàòåëÿ ñ çàãëàâíîé áóêâû" << "\n";
	cin >> sname2;
	counter2 = 0; // Ïðèðàâíèâàåì ñ÷åò÷èê ê 0
	while (now!= NULL) { // Ïðîâåðÿì ñêîëüêî ëþäåé ñ îäèíàêîâûìè ôàìèëèåé
		if (now->sname == sname2) { // ñðàâíèâàåì ôàìèëèè
			counter2++;
			ukaz = now;
		}
		now = now->next; //Ïåðåìåùàåìñÿ â ñëåäóþùóþ "ÿ÷åéêó"
	}
	cout << "Òàêèõ íàéäåíî " << counter2 << "\n";
	if (counter2 > 1) {
		cout << " óòî÷íèòå äàííûå" << "\n";
		cout << "Ââåäèòå èìÿ ïîëüçîâàòåëÿ ñ çàãëàâíîé áóêâû" << "\n";
		cin >> fname2;
		counter2 = 0; // Ïðèðàâíèâàåì ñ÷åò÷èê ê 0
		now = top;
		while (now!= NULL) { // Ïðîâåðÿì ñêîëüêî ëþäåé ñ îäèíàêîâûìè èìåíåì, ôàìèëèåé
			if (now->fname == fname2) { // ñðàâíèâàåì ôàìèëèè
				counter2++;
				ukaz = now;
			}
			now = now->next; //Ïåðåìåùàåìñÿ â ñëåäóþùóþ "ÿ÷åéêó"
		}
		cout << "Òàêèõ íàéäåíî " << counter2 << "\n";
		if (counter2 > 1) {
			cout << " óòî÷íèòå äàííûå" << "\n";
			cout << "Ââåäèòå ãîä ðîæäåíèÿ ïîëüçîâàòåëÿ" << "\n";
			cin >> year2;
			counter2 = 0; // Ïðèðàâíèâàåì ñ÷åò÷èê ê 0
			now = top;
			while (now!= NULL) { // Ïðîâåðÿì ñêîëüêî ëþäåé ñ îäèíàêîâûìè èìåíåì, ôàìèëèåé, ãîäîì
				if (now->year == year2) { // ñðàâíèâàåì ôàìèëèè
					counter2++;
					ukaz = now;
				}
				now = now->next; //Ïåðåìåùàåìñÿ â ñëåäóþùóþ "ÿ÷åéêó"
			}
			if (counter2 > 1) {
				cout << "ß íå ìîãó âûáðàòü èç ïîëíûõ ò¸ñê. Âîéäè â òåêñòîâûé äîêóìåíò 'Baza' è ïîôèêñè ãäå íàïîðòà÷èë! :(" << "\n";
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

str* udal (str *c, str *top)
{
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

str* sortirovka (str *top) 
{
	int counter, i, j;
	str *now = top;
	counter = 0;
	while (now != NULL) {
		counter++;
		now = now->next;
	}
	for (i = 0; i < counter; i++) {
      for (j = 0; j < counter - 1; j++) {
			if (now->year > now->next->year) {
           if (now->priv == NULL) {
              (now->next)->priv = NULL;
           }
           if ((now->next)->next == NULL) {
              now->next = NULL;
              now->priv = now->next;
              (now->next)->next = now;
              (now->next)->priv = now->priv;
           } else {
              now->next = (now->next)->next;
              now->priv = now->next;
              (now->next)->next = now;
              (now->next)->priv = now->priv;
           }
			}
			now = now->next;
		}
		now = top;
	}
}

int main ()
{
	setlocale (0, "");
	int i, n, a, b, c;
	b = 1;
	str *top = NULL;
	str *X;
	while (b == 1) {
		cout << "Ââåäèòå öèôðó." << "\n" << "1. Ââåñòè íîâîãî ïîëüçîâàòåëÿ" << "\n";
		cout << "2. Óäàëèòü ïîëüçîâàòåëÿ" << "\n" << "3. Íàéòè ïîëüçîâàòåëÿ" << "\n";
		cout << "4. Âûâåñòè âñþ ñòðóêòóðó" << "\n" << "5. Îòñîðòèðîâàòü áàçó äàííûõ";
		cout << "\n" << "6. Çàêîí÷èòü ðàáîòó" << "\n";
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
				sortirovka (top);
				break;
			case 6:
				b = 0;
				break;
		}
	}
}
