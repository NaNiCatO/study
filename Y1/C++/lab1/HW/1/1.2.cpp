#include <iostream>
#include <algorithm>
#include <iomanip>

int main(){
    std::cout << "Please enter Warrior name: ";
    std::string War_name;
    std::cin >> War_name;
    std::cout << "Please enter Mage name: ";
    std::string Mage_name;
    std::cin >> Mage_name;
    std::cout << "Please enter Ninja name: ";
    std::string Nin_name;
    std::cin >> Nin_name;
    std::cout << "Please enter Fighter name: ";
    std::string Fight_name;
    std::cin >> Fight_name;
    int s1 = std::max(War_name.size(),Mage_name.size());
    int s2 = std::max(Nin_name.size(),Fight_name.size());
    int size_name = std::max(s1,s2);
    const int size_class = 9 ;
    const int borders = size_name + size_class + 2;
    const std::string corner = "+";
    const std::string middle = "-";
    const std::string horizontal = "=";
    const std::string vertical = "|";

    std::cout << corner ;
    for (int i = 0; i < 2; i++){
        for (int j = 0;j < borders; j++ ){
            std::cout << horizontal ;
        }
        std::cout << corner ;
    }

    std::cout << std::endl << vertical ;
    for (int i = 0; i < 2; i++){
        for (int j = 0;j < borders; j++ ){
            std::cout << " " ;
        }
        std::cout << vertical ;
    }

    std::cout << "\n| " << "Warrior: " << std::left << std::setw(size_name) << War_name << " | " << std::setw(size_class) << "Mage: " << std::setw(size_name) << Mage_name << " |";

    std::cout << std::endl << vertical ;
    for (int i = 0; i < 2; i++){
        for (int j = 0;j < borders; j++ ){
            std::cout << " " ;
        }
        std::cout << vertical ;
    }

    std::cout << std::endl << corner ;
    for (int i = 0; i < 2; i++){
        for (int j = 0;j < borders; j++ ){
            std::cout << middle ;
        }
        std::cout << corner ;
    }

    std::cout << std::endl << vertical ;
    for (int i = 0; i < 2; i++){
        for (int j = 0;j < borders; j++ ){
            std::cout << " " ;
        }
        std::cout << vertical ;
    }

    std::cout << "\n| " << std::left << std::setw(size_class) << "Ninja: " << std::setw(size_name) << Nin_name << " | " << "Fighter: " << std::setw(size_name) << Fight_name << " |";

    
    std::cout << std::endl << vertical ;
    for (int i = 0; i < 2; i++){
        for (int j = 0;j < borders; j++ ){
            std::cout << " " ;
        }
        std::cout << vertical ;
    }

    std::cout << std::endl << corner ;
    for (int i = 0; i < 2; i++){
        for (int j = 0;j < borders; j++ ){
            std::cout << horizontal ;
        }
        std::cout << corner ;
    }
}