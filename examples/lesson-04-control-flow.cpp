#include <iostream>

int main()
{
    int score{};
    std::cin >> score;

    if (score >= 90)
    {
        std::cout << "A\n";
    }
    else if (score >= 80)
    {
        std::cout << "B\n";
    }
    else
    {
        std::cout << "Below B\n";
    }

    for (int i{1}; i <= 5; ++i)
    {
        std::cout << i << '\n';
    }

    return 0;
}
