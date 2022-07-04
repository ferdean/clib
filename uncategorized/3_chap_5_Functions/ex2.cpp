#include <iostream>

void change(int*, int);

int main(int argc, char* argv[]){
    int x = 3;
    int y = 6;

    change(&x, y);

    std::cout << x;

    return 0;
}

void change(int* p_x, int y){
    *p_x = y;
}