#include <iostream>

int main(int argc, char* argv[]){
    int i = 5;
    int *p_j;

    p_j = &i;

    *p_j *= 5;

    int *p_k; 

    p_k = new int;
    
    *p_k = i;
    
    *p_j = 0;

    std::cout << "i = " << i << " *p_j = " << *p_j << " *p_k = " << *p_k;

    return 0;
}