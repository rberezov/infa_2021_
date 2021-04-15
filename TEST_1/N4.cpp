#include <iostream>
#include <iomanip>

struct point
{
    int n;
    double x;
};

void sort(point* mas, int n)
{
    int j = 0;
    point temp;

    for (int i = 0; i < n; i++) {

        j = i;

        for (int l = i; l < n; l++) {
            if (mas[j].x > mas[l].x) {
                j = l;
            }
        }

        temp = mas[i];
        mas[i] = mas[j];
        mas[j] = temp;
    }
}

point min(point* res, int n)
{
    point minim = res[0];

    for (int i = 0; i < n - 1; i++)
    {
        if (res[i].x < minim.x)
        {
            minim.x = res[i].x;
            minim.n = res[i].n;
        }
    }

    return minim;
}

int main()
{
    int n = 0;

    double res = 0;

    std::cin >> n;

    point* mas = new point[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i].x;
        mas[i].n = i + 1;
    }

    sort(mas, n);

    point* result = new point[n - 1];

    if (n != 1)
    for (int i = 1; i < n; i++)
    {
        result[i - 1].x = mas[i].x - mas[i - 1].x;
        result[i - 1].n = i;
    }

    point x = min(result, n);

    std::cout << mas[x.n - 1].n << ' ' << mas[x.n].n;

    delete[]mas;
    delete[]result;

    return 0;
}