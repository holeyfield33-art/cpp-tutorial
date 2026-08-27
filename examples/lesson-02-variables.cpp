#include <iostream>

int main()
{
    const double taxRate{0.0825};
    double price{};

    std::cout << "Enter the price: ";
    std::cin >> price;

    double tax{price * taxRate};
    double total{price + tax};

    std::cout << "Price: $" << price << '\n';
    std::cout << "Tax:   $" << tax << '\n';
    std::cout << "Total: $" << total << '\n';

    return 0;
}
