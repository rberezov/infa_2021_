#include <iostream>

int* generate(int N)
{
    int* mas = new int[N];

    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        mas[i] = rand() % 1000;
    }

    return mas;
}


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
        for (int i = y; i < r - m; i++)
        {
            new_mas[k] = *(m + i);
            k++;
        }
    }

    if (y == r - m)
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

void selection_sort(int* start, int* end)
{
    int k = 0;
    int temp = 0;
    for (int i = 0; &start[i] != end; i++)
    {
        k = i;

        for (int l = i; &start[l] != end; l++)
        {
            if (start[l] < start[k])
            {
                k = l;
            }
        }

        temp = start[i];
        start[i] = start[k];
        start[k] = temp;
    }
}

void merge_sort(int* l, int* m)
{
    int lenght = m - l;
    if (lenght > 64)
    {
        int x = (m - l) / 64;

        for (int i = 1; i < x + 1; i++)
        {
            if (m - (l + 64 * i) > 64)
            {
                selection_sort(l + 64*(i - 1), l + 64*i);
            }
            else
            {
                selection_sort(l + 64 * (i - 1), m);
            }
        }
        for (int i = 1; i < x + 1 ; i++)
        {
            if ((m - (l + 64 * i)) > 64)
            {
                merge(l, l + 64 * i, l + 64 * (i + 1));
            }
            else
            {
                merge(l, l + 64 * i, m);
            }
        }
    }
    else
    {
        selection_sort(l, m);
    }
}

int main()
{
    int N;

    std::cin >> N;
    int* mas = generate(N);

    for (int i = 0; i < N; i++)
    {
        std::cout << mas[i] << ' ';
    }

    std::cout << '\n';

    merge_sort(mas, mas + N);

    for (int i = 0; i < N; i++)
    {
        std::cout << mas[i] << ' ';
    }

    delete[]mas;

    return 0;
}