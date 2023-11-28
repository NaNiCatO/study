#include <iostream>
#include <map>
#include <string>
#include <vector>


auto split(const std::string& s){
    std::vector<std::string> words;
    std::string word;
    for (const auto& c: s){
        if (c == ' '){
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);
    return words;
}

template <class T>
auto pair(const T&vec){
    std::map<std::string, int> sum_num;
    for (int v = 0; v < vec.size();v+=2){
        sum_num[vec[v]] += stoi(vec[v+1]);
    }
    return sum_num;
}

int main(){
    std::string mytext ;
    getline(std::cin, mytext);
    
    auto x = pair(split(mytext));
    for (const auto& h: x){
        std::cout << h.first << " " << h.second << std::endl;
    }
}