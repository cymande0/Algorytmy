#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Sortowanie{

    public:
        void showArr(int* arr, int n){
            for(int i = 0; i < n; i++){
                cout << arr[i] << endl;
            }
        }

        //1. Sortowanie przez proste podstaiwanie
        int* prostew(int* arr, int n){
           int i, j, x;

            for(i = 1; i < n; i++){
                x = arr[i];
                j = i - 1;
                while(j >= 0 && x < arr[j]){
                    arr[j + 1] = arr[j];
                    j -= 1;
                }
                arr[j+1] = x;
            }
            return arr;
        }

        //2. Sortowanie przez wstawianie polowkowe
        int* wsp(int* arr, int n){
            int i, j, q, p, m, x;

            for(i = 1; i < n; i++){
                x = arr[i];
                q = 1;
                p = i - 1;
                while(q <= p){
                    m = (q + p) / 2;
                    if(x < arr[m]){
                        p = m - 1;
                    }
                    else {
                        q = m + 1;
                    }
                }
                for(j = i - 1; j >= q; j--){
                    arr[j+1] = arr[j];
                }
                arr[q] = x;
            }
            return arr;
        }

        //3. Sortowanie przez proste wybieranie
        int* pw(int* arr, int n){
            int i, j, k, x;

            for(i = 0; i < (n-1); i++){
                k = i;
                x = arr[i];
                for(j = i+1; j < n; j++){
                    if(x > arr[j]){
                        k = j;
                        x = arr[j];
                    }
                }
                arr[k] = arr[i];
                arr[j] = x;
            }
            return arr;
        }

        //4. Sortowanie babelkowe
        int* sb(int* arr, int n){
            int i, j, x;

            for(i = 1; i < n; i++){
                for(j = n; j < n; j--){
                    if(arr[j-1] > arr[j]){
                        x = arr[j-1];
                        arr[j-1] = arr[j];
                        arr[j] = x;
                    }
                }
            }
            return arr;
        }

        //5. Sortowanie mieszane
        int* sm(int* arr, int n){
            int j, k, q, p, x;
            q = 2;
            p = n;
            k = n;

            do {
                for(j = p; j < q; j--){
                    if(arr[j-1] > arr[j]){
                        x = arr[j-1];
                        arr[j-1] = arr[j];
                        arr[j] = x;
                    }
                    else {
                        k = j;
                    }
                }
                q = k + 1;
                for(j = q; j < p; j++){
                    if(arr[j-1] > arr[j]){
                        x = arr[j-1];
                        arr[j-1] = arr[j];
                        arr[j] = x;
                    }
                    else{
                        k = j;
                    }
                }
                p = k - j;
            } while(q < p);
            return arr;
        }

        //6. Sortowanie metoda Shella. Najtrudniejsze. Posilkowane internetem.
        int* sortowanieShella(int* arr, int n){

            for (int gap = n / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; i += 1) {
                    int temp = arr[i];
                    int j;
                    for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                        arr[j] = arr[j - gap];
                    }
                    arr[j] = temp;
                }
            }
            return arr;
        }

        //7. Przesiewanie
        void przesiewanie(int q, int p, int* arr){
            int i,j,x;
            i = q;
            j=(2*i)+1;
            x = arr[i];

            while(j <= p){
                if(j<p){
                    if(arr[j] < arr[j+1]){
                        j++;
                    }
                    if(x >= arr[j]){
                        goto stop;
                    }
                }
                arr[i] = arr[j];
                i=j;
                j=2*i;
            }
            stop: arr[i] = x;
        }

        //8. Sortowanie stogowe
        int* sortowanieStogowe(int* arr, int n){

            int q, p, x;

            q = (n/2);
            p = n-1;

            while(q > 0){
                q--;
                przesiewanie(q, p, arr);
            }

            while(p>0){
                x = arr[0];
                arr[0] = arr[p];
                arr[p] = x;
                p--;
                przesiewanie(q, p, arr);
            }

            return arr;
        }


        //9. Sortowanie szybkie metoda rekurecyjna
        int* sortuj(int* arr, int n, int q, int p){

            int i, j, x, w;
            i = q;
            j = p;
            x = arr[(q+p)/2];

            do {

                while(arr[i] < x){
                    i = i + 1;
                }

                while(x < arr[j]){
                    j = j - 1;
                }
                if(i <= j){
                    w = arr[i];
                    arr[i] = arr[j];
                    arr[j] = w;
                    i = i + 1;
                    j = j -1;
                }
                else{
                    break;
                }
            } while(i > j);

            if(q < j ){
                sortuj(arr, n, q, j);
            }
            if(i < p){
                sortuj(arr, n, i, p);
            }

            return arr;
        }

};


int main(){

    cout << "Konrad Pieta INF, studia NN" << endl << endl;
    Sortowanie sortowanie;
    int arr[] = {4,6,3,2,7,4};
    int n = sizeof(arr)/sizeof(*arr);
    int* resultProstew = sortowanie.prostew(arr, n);
    cout << "Wyniki algorytymu: 'Sortowanie przez proste podstawianie:'" << endl;
    sortowanie.showArr(resultProstew, n);
    cout << endl << endl;

    cout << "Wynik algorytmu: 'Sortowanie przez wstawianie polokowe:'" << endl;
    int* resultWsp = sortowanie.prostew(arr, n);
    sortowanie.showArr(resultWsp, n);
    cout << endl << endl;

    cout << "Wynik algorytmu: 'Sortowanie przez poste wybieranie:'" << endl;
    int* resultPw = sortowanie.pw(arr, n);
    sortowanie.showArr(resultPw, n);
    cout << endl << endl;

    cout << "Wynik algorytmu: 'Sortowanie babelkowe':" << endl;
    int* resultSb = sortowanie.sb(arr, n);
    sortowanie.showArr(resultSb, n);
    cout << endl << endl;

    cout << "Wynik algorytmu: 'Sortowanie mieszane':" << endl;
    int* resultSm = sortowanie.sm(arr, n);
    sortowanie.showArr(resultSm, n);
    cout << endl << endl;

    cout << "Wynik algorytmu: 'Sortowanie metoda Shella':" << endl;
    int* resultSortowanieShella = sortowanie.sortowanieShella(arr,n);
    sortowanie.showArr(resultSortowanieShella, n);
    cout << endl << endl;

    cout << "Wynik algorytmu: 'Sortowanie stogowe': " << endl;
    int* resultSortowanieStogowe = sortowanie.sortowanieStogowe(arr,n);
    sortowanie.showArr(resultSortowanieStogowe, n);
    cout << endl << endl;

    cout << "Wyniki algorytmu: 'Sortowanie szybkie metoda rekurecyjna':" << endl;
    int* resultSortowanieSzybkie = sortowanie.sortuj(arr, n, 0, n-1);
    sortowanie.showArr(resultSortowanieSzybkie, n);
    cout << endl << endl;
}

