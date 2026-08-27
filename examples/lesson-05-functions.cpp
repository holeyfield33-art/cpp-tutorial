#include <iostream>

int square(int number)
{
    return number * number;
}

int calculate(int value)
{
    return square(value) + 10;
}

int main()
{
    int result{calculate(5)};
    std::cout << result << '\n';

    return 0;
}
