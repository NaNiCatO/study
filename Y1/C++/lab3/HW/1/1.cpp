#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>


auto split(const std::string& s){
    int i = 0 ;
    std::vector<std::string> words1;
    std::vector<std::string> words2;
    std::vector<std::vector<std::string>> words{words1,words2}; 
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

auto combine(const std::vector<std::vector<std::string>>& w){
    std::vector<std::string> sum ;
    int n = std::max(w[0].size(),w[1].size());
    for (int i = 0 ; i < n ; i++){
        if (i < w[0].size()){
            sum.push_back(w[0][i]);
            if (i < w[1].size()-1){
                sum.push_back(w[1][i]);
            }
        } else{
            sum.push_back(w[1][i]);
        }
    }
    return sum;
}


auto calculate(const std::vector<std::vector<std::string>>& w){
    int sum = 0;
    int n = std::min(w[0].size(),w[1].size());
    for (int i = 0 ; i < n ; i++){
        sum = sum + (stoi(w[0][i]) * stoi(w[1][i]));
    }
    return sum;
}

auto cartesian(const std::vector<std::vector<std::string>>& w){
    std::vector<std::string> list_w ;
    for (int i = 0 ; i < w[0].size() ; i++){
        for (int j = 0 ; j < w[1].size() ; j++){
            std::cout << "(" << std::left << std::setw(2) << w[0][i] << ", ";
            std::cout << w[1][j] << ")" ;
            if ((i != w[0].size()-1) || (j != w[1].size()-1)){
                std::cout <<  ", ";
            }
        }
        std::cout <<  std::endl;
    }
}


int main(){
    std::string myText;
    std::ifstream MyReadFile("data2.txt");
    getline (MyReadFile, myText);
    MyReadFile.close();
    
    auto split_words = split(myText);
    auto com_words = combine(split_words);
    for(const auto& w: split_words[0]){
        std::cout << w << " ";
    }
    std::cout << "; ";
    for(const auto& w: split_words[1]){
        std::cout << w << " ";
    }
    std::cout << std::endl;
    for(const auto& w: com_words){
        std::cout << w << " ";
    }
    std::cout << std::endl << calculate(split_words) << std::endl;

    cartesian(split_words);
    return 0 ;
}