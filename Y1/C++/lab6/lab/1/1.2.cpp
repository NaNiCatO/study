#include <iostream>
#include <string>

void to_upper(char* s) {
    for (auto i = 0 ; i < sizeof(s)*2; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
    }
}

int main(){
    char s[] = {"Hello, World!"};
    to_upper(s);

    std::cout << s  ;
}