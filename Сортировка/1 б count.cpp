#include <iostream>
#include <ctime>
#include <cstdlib>

int* generate(int N)
{
    int* mas = new int[N];

    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        mas[i] = rand() % 5;
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

int count(int* start, int size, int x)
{
    int* Intermediate_result = start;
    int quantity = 0;
    for (int i = 0; Intermediate_result != nullptr; i++)
    {
        Intermediate_result = search(Intermediate_result, start + size , x);

        if ((Intermediate_result == start + size) || (Intermediate_result == nullptr))
        {
            break;
        }
        quantity++;
        Intermediate_result++;
    }

    return quantity;
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

    if (y != nullptr)
    {
        std::cout << count(mas, N, x);
    }
    else
    {
        std::cout << "Not found";
    }



    delete[] mas;

    return 0;
}
