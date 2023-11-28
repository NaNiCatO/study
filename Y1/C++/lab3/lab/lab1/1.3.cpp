#include <iostream>
#include <vector>

std::vector<double> scale(std::vector<double> vec, double N){
    std::vector<double> new_vec ;
    for (auto v: vec){
        new_vec.push_back(v*N);
    }
    return new_vec;
}

std::vector<double> add(std::vector<double> vec_x, std::vector<double> vec_y){
    std::vector<double> new_vec ;
    std::vector<double> min_vec;
    if (vec_y.size() > vec_x.size()){
        min_vec = vec_x;
        vec_x = vec_y;
    }
    else {
        min_vec = vec_y;
    }
    for (int i = 0; i != vec_x.size() ;i++ ){
        if (i < min_vec.size()){
            new_vec.push_back(vec_x[i]+min_vec[i]);
        }
        else{
            new_vec.push_back(vec_x[i]);
        }
    }
    return new_vec;
}



int main(){
    std::vector<double> vec1{2, 1, 4, 3, 7};
    std::vector<double> vec2{1, 3, 2, 5};
    auto vec3 = scale(vec1, 1.5);
    for (auto v: vec3){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    auto vec4 = add(vec2, vec3);
    for (auto v: vec4){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    auto vec5 = add(vec3, scale(vec2, -2.2));
    for (auto v: vec5){
        std::cout << v << " ";
    }

    return 0;
}