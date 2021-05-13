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

int* search(int* start, int* end, int x)
{
    int* result = nullptr;

    for (int i = 0; start + i != end; i++)
    {
        if (*(start + i) == x)
        {
            result = start + i;

            break;
        }
    }

    return result;
}

int main()
{
    int N = 0;
    int x = 0;
    int* y;

    std::cin >> N;

    int* mas;

    mas = generate(N);

    for (int i = 0; i < N; i++)
    {
        std::cout << mas[i] << ' ';
    }

    std::cout << std::endl;

    std::cin >> x;

    y = search(mas, mas + N, x);

    if(y != nullptr)
    { 
        std::cout << y << ' ' << *y;
    }
    else
    {
        std::cout << "Not found";
    }

    delete[] mas;

    return 0;
}
