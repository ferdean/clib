#include <iostream>

void print(int*);


int main(int argc, char* argv[]){
    int x = 6;

    print(&x);
    
    return 0;
}

void print(int* p_x){
    std::cout << *p_x;
}