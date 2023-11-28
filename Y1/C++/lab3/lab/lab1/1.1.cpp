#include <iostream>
#include <vector>

void lshift(std::vector<double>& vec, int N){
    for (int i = 0; i < N; i++){
        vec.erase(vec.begin());
    }
}

void rshift(std::vector<double>& vec, int N){
    for (int i = 0; i < N; i++){
        vec.insert(vec.begin(), 0);
    }
}

int main(){
    std::vector<double> vec{2, 1, 4, 3, 7};
    lshift(vec, 3);
    for (auto v: vec){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    rshift(vec, 2);
    for (auto v: vec){
        std::cout << v << " ";
    }

    return 0;
}