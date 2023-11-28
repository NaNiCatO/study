#include <iostream>
#include <chrono>
#include <ctime>    

int main()
{
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time) << std::endl;
}