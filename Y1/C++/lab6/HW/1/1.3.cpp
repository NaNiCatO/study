#include <iostream>

char hex_digits[] = "0123456789ABCDEF";


char* encode_hex(const char* s) {
    int n = 0;
    const char* p = s;
    while (*p != '\0') {
        n += 2;
        p++;
    }
    char* encoded = new char[n+1];

    char* q = encoded;
    p = s;
    while (*p != '\0') {
        *q++ = hex_digits[(*p >> 4) & 0xF];
        *q++ = hex_digits[*p & 0xF];
        p++;
    }
    *q = '\0';

    return encoded;
}

int main(){
    char word[] = { "Hello, World!" };
    std::cout << encode_hex(word) << std::endl;
}