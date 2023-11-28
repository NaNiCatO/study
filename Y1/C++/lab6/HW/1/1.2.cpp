#include <iostream>


void replace(char* s, char c1, char c2){
    int n = 0;
    while (s[n] != '\0') {
        if (s[n] == c1) {
            s[n] = c2;
        }
        n++;
    }
}

int main(){
    char word[] = { "Hello, World!" };
    replace(word,'l','X');
    std::cout << word << std::endl;
}


        