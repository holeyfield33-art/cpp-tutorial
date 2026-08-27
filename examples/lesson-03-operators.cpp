#include <iostream>

int main()
{
    double price{};
    double quantity{};

    std::cout << "Enter price: ";
    std::cin >> price;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    double subtotal{price * quantity};
    const double freeShippingThreshold{50.0};
    bool qualifiesForFreeShipping{subtotal >= freeShippingThreshold};

    std::cout << "Subtotal: $" << subtotal << '\n';
    std::cout << "Free shipping: "
              << (qualifiesForFreeShipping ? "yes" : "no")
              << '\n';

    return 0;
}
