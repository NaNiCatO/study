#include <iostream>
#include <vector>

std::vector<std::pair<double, double>> create_pairs(const std::vector<double>& arr){
    std::vector<std::pair<double, double>> new_vec ;
    int size = arr.size()/2;
    for (auto i = 0;i < size*2 ; i+=2 ){
        new_vec.push_back( {arr[i],arr[i+1]} );
    }
    return new_vec;
}

int main(){
    std::vector<double> data{1.2, 2.3, 5, 2, 1.1, 3, 7};
    auto pairs = create_pairs(data);
    for (auto p : pairs){
        std::cout << p.first << ", " << p.second << std::endl;
    }
}