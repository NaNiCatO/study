#include <iostream>

char* rev_dup(const char* s){
    char* re_s = new char[sizeof(s)] ;
    for (auto i = 0; i < sizeof(s); i++) {
        re_s[i] = s[sizeof(s)-i-1];
    }
    re_s[sizeof(s)] = '\0';
    return re_s ;
}

int main(){
    char s[] = {"Hello, X"};
    std::cout << rev_dup(s);
}