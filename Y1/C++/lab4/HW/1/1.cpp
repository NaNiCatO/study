#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, double> data;

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

auto set(std::vector<std::string> value){
    data[value[1]] = stod(value[2]);
}

auto get(std::vector<std::string> value){
    if (data.count(value[1]))
    {
        std::cout << value[1]  << ": " << data[value[1]] << std::endl;
    } else {
        std::cout << value[1]  << ": " << "<N/A>" << std::endl;
    }
}

auto add(std::vector<std::string> value){
    if (data.count(value[1]) && data.count(value[2]))
    {
        std::cout << value[1]  << " + " << value[2] << ": " << data[value[1]]+data[value[2]] << std::endl;
    } else {
        std::cout << value[1]  << " + " << value[2] << ": " << "<N/A>" << std::endl;
    }
}

auto sub(std::vector<std::string> value){
    if (data.count(value[1]) && data.count(value[2]))
    {
        std::cout << value[1]  << " - " << value[2] << ": " << data[value[1]]-data[value[2]] << std::endl;
    } else {
        std::cout << value[1]  << " - " << value[2] << ": " << "<N/A>" << std::endl;
    }
}


int main(){
    std::string mytext ;
    while (mytext != "q")
    {
        getline(std::cin, mytext);
        auto input = split(mytext);
        if(input[0] == "set"){
            set(input);
        } else if(input[0] == "get"){
            get(input);
        } else if(input[0] == "add"){
            add(input);
        } else if(input[0] == "sub"){
            sub(input);
        }
    }
    
}