#include <iostream>
#include <ctime>
#include <cstdlib>

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

void selection_sort(int* start, int* end)
{
    if(start != end)
    {
        int k = 0;
        int temp = 0;

        for (int l = 0; start + l != end; l++)
        {
            if (*(start + l) < *(start + k))
            {
                k = l;
            }
        }

        temp = *start;
        *start = *(start + k);
        *(start + k) = temp;

        selection_sort(start + 1, end);
    }
}

int main()
{
    int N = 0;

    std::cin >> N;

    int* mas;

    mas = generate(N);

    for (int i = 0; i < N; i++)
    {
        std::cout << mas[i] << ' ';
    }
    std::cout << std::endl;

    selection_sort(mas, mas + N);

    for (int i = 0; i < N; i++)
    {
        std::cout << mas[i] << ' ';
    }

    delete[] mas;

    return 0;
}
