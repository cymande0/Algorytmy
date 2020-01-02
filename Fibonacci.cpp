#include <iostream>
#include <string>

using namespace std;
class Fibonacci {
public:

	void fibo() {
		long a, b, c;
		string i, liczba, word;

		cout << "Podaj, ktora liczba z ciagu Fibonacciego: ";
		cin >> liczba;
		int liczbaInt = stoi(liczba);

		a = 1;
		b = 1;

		if (liczbaInt <= 2) {
			cout << "Wynik: " << a << endl;
		}
		else {
			for (int i = 2; i<stoi(liczba); i++) {
				c = a + b;
				a = b;
				b = c;
			}
			cout << "Wynik: " << c;
		}
	}

	int fiboReku(int nr) {
		if ((nr == 1) || (nr == 2)) {
			return 1;
		}
		else {
			return fiboReku(nr - 1) + fiboReku(nr - 2);
		}
	}

};
int main()
{
	Fibonacci fiboObj;
	fiboObj.fibo();
	int n = 8;
	cout << endl << "Fibo rekurencyjnie z 8: " << fiboObj.fiboReku(n);

}
