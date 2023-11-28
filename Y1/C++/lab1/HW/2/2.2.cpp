#include <iostream>
#include <iomanip>

int main(){
    int f;
    double c;
    std::cout << std::left << std::setw(5) << "Fahr" << "Celcius\n" ;
    for (f = 0; f <= 300; f = f + 40){
        c = (5.0/9.0) * (f - 32);
        std::cout << std::left << std::setw(5) << f << std::fixed << std::setprecision(1) << c << std::endl;
    }
}