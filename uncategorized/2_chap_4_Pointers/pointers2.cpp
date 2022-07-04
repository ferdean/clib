#include <iostream>

int main(int argc, char* argv[]){
    int x = 1;
    int y = 2;
    int *p_x, *p_y, *p_k;

    std::cout << "Original values:\t" << "x = " << x << " y = " << y;

    p_x = &x;
    p_y = &y;
    p_k = new int;

    *p_k = *p_x;
    *p_x = *p_y;
    *p_y = *p_k;

    std::cout << "\nMixed values:\t\t" << "x = " << x << " y = " << y;

    delete[] p_k;    

    return 0;
}