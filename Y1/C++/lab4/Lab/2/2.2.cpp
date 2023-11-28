#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

template <class T>
auto all_zeroes(const T& vec_begin, const T& vec_end){
    for (auto value = vec_begin; value != vec_end; ++value){
        if (*value != 0){
            return false;
        }
    }
    return true;
}





int main(){
    std::vector<int> vec1{1, 0, 2, 3};
    std::vector<int> vec2(10);
    bool z1 = all_zeroes(vec1.begin(), vec1.end());
    bool z2 = all_zeroes(vec2.begin(), vec2.end());
    std::list<int> li1(vec1.rbegin(), vec1.rend());
    std::list<int> li2(10);
    bool zz1 = all_zeroes(li1.begin(), li1.end());
    bool zz2 = all_zeroes(li2.begin(), li2.end());
    std::cout << std::boolalpha << z1 << std::endl << z2 << std::endl << zz1 << std::endl << zz2;
}