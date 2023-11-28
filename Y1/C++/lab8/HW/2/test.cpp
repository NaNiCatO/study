#include <iostream>
#include <string>
auto crypt_text(std::string& text){
    std::string result = text;
    for (auto& i : result){
        if('A' <= i && i <= 'Z'){
            i = char('Z' - (i-'A'));
        }
        else if('a' <= i && i <= 'z'){
            
            i = char('z' - (i-'a'));
        }
    }
    return result ;
}

int main() {
    std::string x = "abcdef";
    char c = 'Z';
    std::cout << crypt_text(x) << std::endl;
    
}
