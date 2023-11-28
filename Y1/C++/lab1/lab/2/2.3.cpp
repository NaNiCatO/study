#include <iostream>
#include <string>    
int main()
{
    const int pad = 1;
    const int rows = pad * 2 + 3;
    std::cout << "Please enter P1 name: ";
    std::string p1_name;
    std::cin >> p1_name;
    std::cout << "Please enter P2 name: ";
    std::string p2_name;
    std::cin >> p2_name;
    int size1 = ("Player 1: " + p1_name).size();
    int size2 = ("Player 2: " + p2_name).size();
    std::cout << "+" ;
    for (int j = 0; j <= size1+1; j++){
        std::cout << "=" ;
    }
    std::cout << "+" ;
    std::cout << "\n|" ;
    for (int j = 0; j <= size1+1; j++){
        std::cout << " " ;
    }
    std::cout << "|\n| " << "Player 1: " << p1_name << " |\n";
    std::cout << "|" ;
    for (int j = 0; j <= size1+1; j++){
        std::cout << " " ;
    }
    std::cout << "|\n" ;
    std::cout << "+" ;
    for (int j = 0; j <= size1+1; j++){
        std::cout << "=" ;
    }
    std::cout << "+" ;
    
    //
    std::cout << "\n|" ;
    for (int j = 0; j <= size2+1; j++){
        std::cout << " " ;
    }
    std::cout << "|\n| " << "Player 2: " << p2_name << " |\n";
    std::cout << "|" ;
    for (int j = 0; j <= size2+1; j++){
        std::cout << " " ;
    }
    std::cout << "|\n" ;
    std::cout << "+" ;
    for (int j = 0; j <= size2+1; j++){
        std::cout << "=" ;
    }
    std::cout << "+" ;
    


    return 0;
}
