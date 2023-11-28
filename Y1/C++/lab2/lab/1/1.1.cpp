#include <iostream>


auto tri_pattern(int size){
    std::string ans ;
    for (int i = 0; i <= size * 2 -1; i++){
        if (i <= size){
            for (int j = 0; j < i; j++) {
                ans += "*" ;  
            }
        }
        else {
            for (int j = (size * 2 -1)-i; j >= 0; j--) {
                ans += "*" ;
            }
        }
        ans += "\n" ;
    }
    return ans ;
}

int main(){
    auto s = tri_pattern(4) ;
    std::cout << s;
    return 0 ;
}