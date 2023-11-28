#include <iostream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
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

int main(){
    std::string m = "C *C++* Rust* *Python* * *Java";
    auto words = split(m, ' ');
    auto s = words.begin();
    std::cout << *s << std::endl;
    for (auto it = words.begin(); it != words.end(); it++){
        std::cout << *it << std::endl;
    }
}