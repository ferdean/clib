#include <iostream>

int main(int argc, char* argv[]){

    double x;
    double *p_x;

    x   = 1.0;
    p_x = &x;

    std::cout << "x = " << x << " at location " << p_x;

    x   = 2.0;

    std::cout << "\nNow, we changed directly x = " << x << " at location " << p_x;

    *p_x = 3.0;

    std::cout << "\nNow, we changed via pointer x = " << x << " at location " << p_x;

    return 0;
}