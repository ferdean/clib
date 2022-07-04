#include <cassert>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{ 
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    std::ofstream write_doc("main.dat");
    assert(write_doc.is_open());

    write_doc.setf(std::ios::scientific);
    write_doc.precision(10);
    write_doc.setf(std::ios::showpos);


    for (unsigned int i = 0; i<4; i++){
        write_doc << x[i] << " ";
    }

    write_doc.flush();
    write_doc << "\n";
    
    for (unsigned int i = 0; i<4; i++){
        write_doc << y[i] << " ";
    }

    write_doc.flush();
    write_doc.close();

    return 0;
}