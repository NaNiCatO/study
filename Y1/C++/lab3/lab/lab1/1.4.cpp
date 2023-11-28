#include <iostream>
#include <iterator>
#include <list>

void remove_negative(std::list<double>& list){
    for (auto value = list.begin(); value != list.end();){
        if (*value < 0.0){
            value = list.erase(value);
        }
        else{
            ++value;
        }
    }
}


int main(){
    std::list<double> list{0.8, -5.1, 1.6, -6.5, 10.5};
    remove_negative(list);
    for (auto iter = list.begin(); iter != list.end(); ++iter){
        std::cout << *iter << " ";
    }
    return 0;
}