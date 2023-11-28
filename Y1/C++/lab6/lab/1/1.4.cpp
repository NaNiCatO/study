#include <iostream>
#include <vector>
#include <string>


auto split(const std::string& s){
    std::string word;
    for (const auto& c: s){
        if (c == '!'){
            return word;
        } else {
            word += c;
        }
    }
    return word;
}

char* read_text(std::istream& is){
    char* word = new char[100];
    char c ;
    int i;
    while (is.get(c)){
        if (c == '!'){
            break ;
        } else {
            word[i] = c;
        }
        i++;
    }
    word[i] = '\0';
    return word;
}


int main(){
    //Hello, X! Y!, Z
    auto x = read_text(std::cin);
    std::cout << x ;
}