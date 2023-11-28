#include <vector>
#include <array>
#include <iostream>

int main(){
    double coords[3] = {} ;
    double* p1 = coords ;
    std::cout << "coords : " << sizeof(coords) << std::endl ;
    std::cout << "p1 : " << sizeof(p1) << std::endl ;
    std::cout << "compute the number of elements : " <<  sizeof(coords)/sizeof(*coords) <<  std::endl ;
    int i = 0 ;
    std::cout << "compute the number of elements : " << sizeof(coords)/sizeof(p1) << std::endl ;
    std::cout << "******" << std::endl ;

    std::array<double, 4> pt4d ;
    auto arr_it = pt4d.begin() ;
    std::cout << "pt4d : " << sizeof(pt4d) << std::endl ;
    std::cout << "arr_it : " << sizeof(arr_it) << std::endl ;
    std::cout << "******" << std::endl ;

    std::vector<double> vec;
    auto vec_it = vec.begin(); 
    std::cout << "pt4d : " << sizeof(vec) << std::endl ;
    std::cout << "pt4d : " << sizeof(vec_it) << std::endl ;
    std::cout << "compute the number of elements : " << sizeof(vec)/sizeof(vec.begin()) << std::endl ;

    std::cout << "******" << std::endl ;
}