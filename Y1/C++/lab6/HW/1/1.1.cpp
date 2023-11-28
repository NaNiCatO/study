#include <iostream>

void inverse_numbers(double* v, size_t n){
    for (auto i = 0; i < n; i++) {
        v[i] = -v[i];
    }
}

int main(){
    double values[] = { 1.0, 1.5, 2.9 };
    size_t size = sizeof(values) / sizeof(*values);
    inverse_numbers(values, 2);
    for (auto i = 0; i < size; i++) {
        std::cout << values[i] << std::endl;
    }
    
}