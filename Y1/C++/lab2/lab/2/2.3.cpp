#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>


auto split(std::string m, char d){
    std::vector<std::string> result;
    std::string line;
    std::stringstream stream(m);

    while (std::getline(stream, line, d)){
        result.push_back(line);
    }

    return result;
}

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
    std::string m ;
    std::getline(std::cin, m);
    auto words = split(m, ' ');
    std::cout << "<table>" << std::endl ;
    for (const auto& w: words) {
        std::cout << "<tr>" << std::endl ;
        std::cout << "\t<td>" << std::endl ;
        std::cout << "\t" << w << std::endl;
        std::cout << "\t<td>" << std::endl ;
        std::cout << "\t<td>" << std::endl ;
        std::cout << "\t" << unstylize(w) << std::endl;
        std::cout << "\t<td>" << std::endl ;
        std::cout << "\t<td>" << std::endl ;
        std::cout << "\t" << stylize(w) << std::endl;
        std::cout << "\t<td>" << std::endl ;
        std::cout << "</tr>" << std::endl ;
    }
    std::cout << "</table>" << std::endl ;
    return 0 ;
}