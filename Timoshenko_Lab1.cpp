#include <iostream>
#include <string>
#include <fstream>


using namespace std;
void sorter(int* A, int N);
void creat_mas(int* A, int N);
void sgutia_mas(int* A, int N);

int main()

{
    setlocale(LC_ALL, "ru");

    int zad; cout << "Введите номер программы(1 или 2): " << endl; cin >> zad;

    
        if (zad == 1)
        {
            
            int i, n = 0, p = 0, j = 0;
            ifstream F1;
            ofstream F2;
            F2.open("Nash massiv.txt", ios::out);
            F1.open("Data.txt", ios::in);
            while (!F1.eof())

            {

                F1 >> p;

                if ((p % 2) == 0)

                    n++;

            }

            F1.close();
            int* a = new int[n];
            F1.open("Data.txt", ios::in);
            while (!F1.eof())
            {
                F1 >> p;
                if ((p % 2) > 0)
                {
                    a[j] = p;
                    j += 1;
                }
                sorter(a, n);
            }
            for (i = 0; i < n; i++)
            {
                F2 << a[i] << endl;
            }
            cout << "Задача выполнена." << endl;
            F1.close();
            F2.close();

        }
        if (zad == 2)
        {
            int N = rand() % 1 + 101;
            int* A = new int[N];
            creat_mas(A, N);
            sgutia_mas(A, N);
            cout << "Задача выполнена." << endl;
        }
    
    return 0;
}

void sorter(int* a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j > 0; j--) if (a[j] > a[j - 1])
        {
            a[j] = a[j] + a[j - 1];
            a[j - 1] = a[j] - a[j - 1];
            a[j] = a[j] - a[j - 1];
        }
    }
}
void creat_mas(int* A, int N)
{
    fstream arr2;
    arr2.open("massive(a_b).txt", fstream::in | fstream::out);
    int a, b;
    cout << "Необходимо ввести диапазон элементов массива [a,b]." << endl;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    while (a > b || a == b)
    {
        if (a > b || a == b) cout << "Невозможно. Должно выполняться условие: a меньше b и a не равно b." << endl;
        cout << "Введите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;
    }
    int p; p = (b - a);
    for (int i = 0; i <= N; i++)
    {
        arr2 <<  rand() %p + a << endl;
    }
    arr2.close();
}
void sgutia_mas(int* A, int N)
{
    fstream arr2;
    arr2.open("massive(a_b).txt", fstream::in | fstream::out);
    for (int i = 0; i < N; i++)
    {
        
        if ((A[i] % 2)==0)
        {
    
            A[i] ;
            
        }

    }

    arr2.close();

}

