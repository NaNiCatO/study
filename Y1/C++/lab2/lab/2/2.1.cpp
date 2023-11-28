#include <iostream>
#include <string>
#include <iomanip>

std::string unstylize(const std::string& word){
    if (word.front() == '*' && word.back() == '*'){
        return word.substr(1,word.size()-2);
    }
    return word ;
}

std::string stylize(const std::string& word){
    if (word.front() == '*' && word.back() == '*'){
        return "<strong>" + word.substr(1,word.size()-2) + "</strong>";
    }
    return word ;
}

int main()
{
    auto words = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};
    std::cout << std::left << std::setw(15) << " " << std::setw(15) << "unstylize" << "stylize" << std::endl;
    for (const auto& w: words) {
        std::cout << std::left << std::setw(15) << w << std::setw(15) << unstylize(w) << stylize(w) << std::endl;
    }
    return 0 ;
}