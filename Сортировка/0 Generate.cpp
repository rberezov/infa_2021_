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

    delete[] mas;

    return 0;
}
