#include <iostream>

void merge(int* l, int* m, int* r)
{
    int* new_mas = new int[r - l];
    int x = 0;
    int y = 0;
    int k = 0;
    for (; ; k++)
    {
        if ((l + x == m) || (m + y == r))
        {
            break;
        }
        if (*(l + x) > *(m + y))
        {
            new_mas[k] = *(m + y);
            y++;
        }
        else
        {
            new_mas[k] = *(l + x);
            x++;
        }

    }

    if (x == m - l)
    {
        for (int i = y; i < r - m ; i++)
        {
            new_mas[k] = *(m + i);
            k++;
        }
    }

    if (y == r - m )
    {
        for (int i = x; i < m - l; i++)
        {
            new_mas[k] = *(l + i);
            k++;
        }
    }

    for (int i = 0; i < r - l; i++)
    {
        *(l + i) = new_mas[i];
    }

    delete[]new_mas;
}

int main()
{
    int N = 0;
    int M = 0;

    std::cin >> N >> M;

    int* mas = new int[N + M];

    for (int i = 0; i < N + M; i++)
    {
        std::cin >> mas[i];
    }

    merge(mas, mas + N, mas + N + M);

    for (int i = 0; i < N + M; i++)
    {
        std::cout << mas[i] << ' ';
    }

    delete[]mas;

    return 0;
}