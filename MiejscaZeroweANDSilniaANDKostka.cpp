#include <iostream>
#include <math.h>
#include<cstdio>
#include <cstdlib>
#include<string>

using namespace std;

class Cwiczenia1{

public:
    void liczMiejscaZerowe(){
        float delta, a, b, c, x1, x2;

         cout << "Podaj wspolczynnik a, b, c trojmianinu kwadratowego: " << endl;
         cin >> a;
         cin >> b;
         cin >> c;

         if(a == 0){
            cout << "To nie jest funkcja kwadratowa. ";
         }
         else{
            delta = pow(b,2) - (4*a*c);
            cout << "Delta wynosi: " << delta << endl;
            if(delta < 0){
                cout << "Brak miejsc zerowych funckji.";
            }
            else{
                if(delta > 0){
                    x1 = ((-b) - sqrt(delta)) / (2*a);
                    x2 = ((-b) + sqrt(delta)) / (2*a);
                    printf("X1 = %.3f\n", x1);
                    printf("X2 = %.3f\n", x2);
                }
                else{
                    x1 = (-b) / (2*a);
                    printf("X1: %.3f\n", x1);
                }
            }
         }
    }

    int silniaLiczby(int n){
        int silnia;
        if(n == 0){
            silnia = 1;
        }
        else{
            silnia = (n * silniaLiczby(n-1));
        }
        return silnia;
    }

    void kostka(){
        int kost;
        string znak;

        do{
            cout << "Ilu scienna kostka chcesz grac?" << endl;
            cin >> kost;
            if(kost < 4){
                cout << "Kostka musi miec min 4 sciany." << endl;
            }
        } while(kost < 4);

        do{
            int wylosowana_liczba =( std::rand() % kost) + 1;
            cout << "Wylosowano: " << wylosowana_liczba << endl;
            cout << "Aby zakonczyc wcisnij 'q'." << endl;
            cin >> znak;
        } while(znak.compare("q") && znak.compare("Q"));
    }
};
int main(){

    Cwiczenia1 cw;
    cout << "1. Miejsca zerowe." << endl;
    cw.liczMiejscaZerowe();

    int n;
    cout << endl << "2. Program obliczania silnia z dowolnej liczby." << endl;
    cout << "podaj liczbe: ";
    cin >> n;
    int resultsilnia = cw.silniaLiczby(n);
    cout << "Silnia z " << n << " wynosi: " << resultsilnia;
    cout << endl << endl << "3. Program kostka.";
    cw.kostka();


}
