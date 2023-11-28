#include <iostream>
int main()
{
    int size ;
    std::cout << "Output size = " ;
    std::cin >> size ;
    for (int i = 0; i <= size * 2 -1; i++){
        if (i <= size){
            for (int j = 0; j < i; j++) {
                std::cout << "*" ;
            }
        }
        else {
            for (int j = (size * 2 -1)-i; j >= 0; j--) {
                std::cout << "*" ;
            }
        }
        std::cout << "\n" ;
    }

}