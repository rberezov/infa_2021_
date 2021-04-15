#include <iostream>
#include <iomanip>

int main()
{
    int n = 0;

    double res = 0;
    double x = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;

        res = res + x;
    }

    std::cout << std::fixed << std::setprecision(10);

    std::cout << res / n;

    return 0;
}
