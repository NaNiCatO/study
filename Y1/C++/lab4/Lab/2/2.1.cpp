#include <algorithm>
#include <vector>
#include <iostream>
#include <list>


template <class T>
T remove_negative(const T& vec){
    T list = vec;
    //copy(vec.begin(),vec.end(),back_inserter(list));
    for (auto value = list.begin(); value != list.end();){
        if (*value < 0.0){
            value = list.erase(value);
        }
        else{
            ++value;
        }
    }
    return list;
}

template <class T>
auto print(const T& vec){
    for (auto v: vec){
        std::cout << v << " ";
    }
    std::cout << std::endl ;
}

int main(){
    std::vector<double> vec1{
        0.8, -5.1, 1.6, -6.5, 10.5
    };
    auto vec2 = remove_negative(vec1);
    print(vec1);
    print(vec2);
    std::list<double> li1(vec1.rbegin(), vec1.rend());
    print(li1);
    auto li2 = remove_negative(li1);
    print(li2);
    return 0;
}