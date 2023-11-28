#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

template <class T>
auto str_join(std::string x,const T& word_begin,const T& word_end){
    std::string sum ;
    for(auto value = word_begin; value != word_end; ++value){
        sum += *value;
        if (std::next(value) != word_end){
            sum += x ;
        }
    }
    return sum;
}


int main(){
    auto words = std::vector<std::string>{"C", "Rust", "C++", "Python"};
    auto str1 = str_join(std::string(", "), words.begin(), words.end());
    std::cout << str1 << std::endl;
    auto words2 = std::list<std::string>(words.rbegin(), words.rend());
    auto str2 = str_join(std::string(", "), words2.begin(), words2.end());
    std::cout << str2 << std::endl;

}