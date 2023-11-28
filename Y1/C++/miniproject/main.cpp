#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "./print_format_html.hpp"


std::vector<int> read_data(std::string text){
    std::vector<int> list_value;
    std::string member ; 
    for(const auto& value: text) {
        if (value == ' '){
            if(member != ""){
                list_value.push_back(stoi(member));
            }
            member = "";
        } else {
            member += value;
        }
    }
    list_value.push_back(stoi(member));
    return list_value;
}

int main(){
    std::string text, key ;
    std::ifstream ReadFile("./data.txt");
    std::map<std::string, std::vector<int>> data_input;
    while (std::getline(ReadFile,text))
    {
        if (text.substr(0,7) == "Title: "){
            key = text.substr(7);
            data_input[key];
        } else {
            data_input[key] = read_data(text);
        }
    }
    for(auto it=data_input.begin(); it!=data_input.end(); ++it){
        std::cout << it->first << std::endl;
        for(const auto& value: it->second) {
        std::cout << value << ", ";
        }
        std::cout << std::endl ;
    }
    html_format("./output.html",data_input);
}