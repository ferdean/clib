#include <iostream>
#include <cmath>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[]){
    
    int nN;
    double h;
    double yn_1 = 1.0, x = 0.0;
    double yn, y_exact;

    std::cout << "Specify the number of gridpoints: ";
    std::cin >> nN;

    assert(nN > 1);

    h = 1/((double)(nN) - 1);

    std::cout << "h = " << h;

    std::ofstream write_result("xy.dat");
    assert(write_result.is_open());

    write_result.precision(6);

    write_result << "x" << " " << "y" << " " << "ytilde" << "\n";

    for (unsigned int i = 0; i < nN; i++){
        y_exact = exp(- x);
        yn      = yn_1 / (1 + h);

        write_result << x << " " << y_exact << " " << yn_1 <<"\n";
        write_result.flush();

        yn_1 = yn;
        x   += h;
    }


    write_result.close();

    return 0;
}
