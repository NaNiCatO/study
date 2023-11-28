#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

auto split(std::string m, char d){
    std::vector<std::string> result;
    std::string line;
    std::stringstream stream(m);

    while (std::getline(stream, line, d)){
        result.push_back(line);
    }

    return result;
}

bool compare(std::vector<std::string> x, std::vector<std::string> y){

    return *max_element(x.erase(x.begin()), x.end()) >= *max_element(y.erase(y.begin()), y.end());
}

int main(){
    int i = 1;
    std::vector<std::vector<std::string>> list_score;
    std::string myText;
    std::ifstream MyReadFile("score.txt");
    while (std::getline (MyReadFile, myText)) {
        auto list_w = split(myText, ' ');
        list_score.push_back(list_w);
    }
    MyReadFile.close();
    std::sort(list_score.begin(), list_score.end(), compare);
    for (auto& list_value: list_score) {
        std::cout << i << ". " << list_value[0] << "\t"  << *max_element(list_value.erase(list_value.begin()), list_value.end()) << std::endl;
        i +=1 ;
    }
}