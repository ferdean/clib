#include <iostream>

int main(int argv, char* argc[])
{
    int x, y;

    std::cout << "X: ";
    std::cin >> x;
    std::cout << "\nY: ";
    std::cin >> y;

    if (y == 0){
        std::cerr << "Error - division by 0.";
    }
    else {
        std::cout << x/y;
    }
}