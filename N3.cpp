#include <iostream>
#include <iomanip>


void sort(double* mas, int n)
{
    int j = 0;
    double temp = 0;

    for (int i = 0; i < n; i++) {

        j = i;

        for (int l = i; l < n; l++) {
            if (mas[j] > mas[l]) {
                j = l;
            }
        }

        temp = mas[i];
        mas[i] = mas[j];
        mas[j] = temp;
    }
}

int main()
{
    int n = 0;

    double res = 0;

    std::cin >> n;

    double* mas = new double[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }

    sort(mas, n);

    std::cout << mas[n/2];

    delete[] mas;

    return 0;
}