#include <iostream>

char* substitute(char* text, char* word, char* rep){
    int len = 0;
    while(text[len] != '\0'){
        len++;
    }

    int word_len = 0;
    while(word[word_len] != '\0'){
        word_len++;
    }

    int rep_len = 0;
    while (rep[rep_len] != '\0') {
        rep_len++;
    }

    if (word_len == 0) return text;

    char* new_text = new char[len + 1];

    int i = 0;
    int j = 0;
    while (i < len) {
        bool match = true;
        for (int k = 0; k < word_len; k++) {
            if (text[i+k] != word[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            for (int k = 0; k < rep_len; k++) {
                new_text[j++] = rep[k];
            }
            i += word_len;
        } else {
            new_text[j++] = text[i++];
        }
    }

    new_text[j] = '\0';

    return new_text;
}



int main(){
    char text1[] = "abc python javapythonx";
    char text2[] = "abcx yja helx yz01 23";
    std::cout << (substitute(text1, "python", "rust")) << std::endl;
    std::cout << (substitute(text1, "", "rust")) << std::endl;
    std::cout << (substitute(text2, "python", "rust")) << std::endl;
    std::cout << (substitute(text2, "x y", "a b")) << std::endl;
}