#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


auto split(const std::string& s){
    std::vector<std::string> words1, words2 ;
    std::vector<std::vector<std::string>> words{words1,words2}; 
    std::string word;
    for (const auto& c: s){
        if (c == ' ' && word.front() == '*' && word.back() == '*' && word.size() > 1){
            words[0].push_back(word);
            word = "";
        } else if (c == ' '){
            words[1].push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    if (word.front() == '*' && word.back() == '*' ){
        words[0].push_back(word);
    } else{
        words[1].push_back(word);
    }
    return words;
}

auto cartesian(const std::vector<std::vector<std::string>>& w){
    std::vector<std::string> list_w ;
    for (int i = 0 ; i < w[0].size() ; i++){
        for (int j = 0 ; j < w[1].size() ; j++){
            std::cout << "(" << w[0][i] << ", " << w[1][j] << ")" ;
            if ((i != w[0].size()-1) || (j != w[1].size()-1)){
                std::cout <<  ", ";
            }
        }
        std::cout <<  std::endl;
    }
}

int main(){
    std::string myText;
    std::ifstream MyReadFile("data1.txt");
    getline (MyReadFile, myText);
    MyReadFile.close();
    auto split_words = split(myText);
    cartesian(split_words);
    return 0 ;
}