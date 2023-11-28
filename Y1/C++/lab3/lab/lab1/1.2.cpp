#include <iostream>
#include <vector>

void remove_negative(std::vector<double>& vec){
    for (auto value = vec.begin(); value != vec.end();){
        if (*value < 0){
            vec.erase(value);
        }
        else{
            ++value ;
        }
    }
}


int main(){
    std::vector<double> vec{0.8, -5.1, 1.6, -6.5, 10.5};
    remove_negative(vec);
    for (auto v: vec){
        std::cout << v << " ";
    }
    return 0;
}