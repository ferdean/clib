#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    int data[5];
    double average;
    double sum = 0.0;

    int length = sizeof(data)/sizeof(data[0]);

    for (unsigned int i = 0; i < length; i++){
        std::cout << "Cars in day " << i + 1 << ": ";
        std::cin >> data[i];
        sum += (double)(data[i]);
    }

    average = sum/length;
    
    std::cout << "Average is " << average;

    return 0;
}