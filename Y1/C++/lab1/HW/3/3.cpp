#include <iomanip>
#include <iostream>
#include <cmath>
#include <random>

int main()
{
    constexpr double rnd_min = 0, rnd_max = 1;
    std::random_device rd;
    std::default_random_engine generator(rd()); 
    std::uniform_real_distribution<double> distribution(rnd_min,rnd_max);
    std::cout << std::fixed << std::setprecision(4);
    int N;
    std::cout << "Number of random numbers :";
    std::cin >> N;
    double sum = 0.0 ;
    for (int i = 0; i<N; i++){
        sum = sum + std::pow((0.5-distribution(generator)),2);
    }
    std::cout << "MSE = " << sum/N;
    return 0;
}