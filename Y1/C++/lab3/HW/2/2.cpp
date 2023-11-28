#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>


auto split(const std::string& s){
    int i = 0 ;
    std::vector<std::string> words1, words2 , words3;
    std::vector<std::vector<std::string>> words{words1,words2,words3}; 
    std::string word;
    for (const auto& c: s){
        if (c == ' '){
            words[i].push_back(word);
            word = "";
        } else if (c == ';'){
            words[i].push_back(word);
            i++ ;
        } else {
            word += c;
        }
    }
    words[i].push_back(word);
    words[i].erase(words[i].begin());
    return words;
}

auto find_average(const std::vector<std::vector<std::string>>& words){
    double sum = 0.0;
    for(const auto& list_v: words){
        for(const auto& value: list_v){
            sum = sum + stod(value) ;
        }
        std::cout << std::setprecision(3) << sum/list_v.size() << " ";
        sum = 0.0;
    }
}

auto cartesian(const std::vector<std::vector<std::string>>& w){
    std::vector<std::string> list_w ;
    for (int i = 0 ; i < w[0].size() ; i++){
        for (int j = 0 ; j < w[1].size() ; j++){
            for (int k = 0 ; k < w[2].size() ; k++){
                std::cout << "(" << std::left << std::setw(2) << w[0][i] << ", ";
                std::cout << w[1][j] << ", " << w[2][k]<< ")" ;
                if ((i != w[0].size()-1) || (j != w[1].size()-1) || (k != w[2].size()-1)){
                    std::cout <<  ", ";
                }
            }
        }
        std::cout <<  std::endl;
    }
}

int main(){
    std::string myText;
    std::ifstream MyReadFile("data.txt");
    getline (MyReadFile, myText);
    MyReadFile.close();
    
    auto split_words = split(myText);
    find_average(split_words);
    std::cout <<  std::endl;
    cartesian(split_words);
    return 0 ;
}