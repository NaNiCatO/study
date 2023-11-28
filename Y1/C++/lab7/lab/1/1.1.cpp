#include <iostream>
#include <string>

auto substitute(const std::string& text, const char* word, const char* rep){
    std::string result = text;
    int word_len = 0;
    while (word[word_len] != '\0') {
        word_len++;
    }
    size_t pos = result.find(word);
    if (pos != std::string::npos) {
        result.replace(pos, word_len, rep);
    }
    return result ;
}

int main(){
    std::string text1 = "abc python javapythonx";
    std::string text2 = "abcx yja helx yz01 23";
    std::cout << substitute(text1, "python", "rust") << std::endl;
    std::cout << substitute(text1, "", "rust") << std::endl;
    std::cout << substitute(text2, "python", "rust") << std::endl;
    std::cout << substitute(text2, "x y", "a b") << std::endl;
}






