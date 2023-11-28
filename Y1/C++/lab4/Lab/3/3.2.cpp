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
    std::map<std::string, std::string> sum_num;
    for (int i = 0; i < vec.size();i+=2){
        if (sum_num.find(vec[i]) != sum_num.end()){
            sum_num[vec[i]] += ", " + vec[i+1];
        } else {
            sum_num[vec[i]] = vec[i+1];
        }
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