#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

std::string unstylize(const std::string& word){
    if (word.size() < 2){
        return word ;
    }
    else if (word.front() == '*' && word.back() == '*'){
        return word.substr(1,word.size()-2);
    }
    return word ;
}

auto split(std::string m, char d){
    std::vector<std::string> result;
    std::string line;
    std::stringstream stream(m);

    while (std::getline(stream, line, d)){
        result.push_back(line);
    }

    return result;
}


int main(){
    // C *C++* Rust* *Python* * *Java
    std::string m;
    std::cout << "Enter the string: ";
    std::getline(std::cin, m);
    auto words = split(m, ' ');
    std::reverse(words.begin(), words.end());
    for (const auto& w: words) {
        std::cout << unstylize(w) << std::endl;
    }
    return 0 ;
}