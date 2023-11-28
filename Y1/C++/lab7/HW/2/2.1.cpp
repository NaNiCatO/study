#include <vector>
#include <iostream>
#include <algorithm>

struct Point{
    double x ;
    double y ;
};

auto create_point_list(const std::vector<double>& l_x, const std::vector<double>& l_y){
    std::vector<Point> result ;
    auto loop_n = std::min(l_x.size(),l_y.size());
    for(auto i = 0 ; i != loop_n ; i++){
        result.push_back({l_x[i],l_y[i]});
    }
    return result;
}

auto split_point_fields(const std::vector<Point>& point_list){
    std::vector<std::vector<double>> result{{},{}} ;
    for(auto i : point_list){
        result[0].push_back(i.x);
        result[1].push_back(i.y);
    }
    return result ;
}


int main(){
    std::vector<double> points_x {1.2, 1.5, 10, 25.6};
    std::vector<double> points_y {0.9, 2.5, 3, 4.5};
    
    auto point_list = create_point_list(points_x,points_y);
    for (auto i : point_list){
        std::cout << i.x << "\t" << i.y << std::endl;
    }
    
    
    auto list_x_y = split_point_fields(point_list);
    
    std::cout << "==========list x===========" << std::endl;
    for (auto i : list_x_y[0]){
        std::cout << i << std::endl;
    }

    std::cout << "==========list y===========" << std::endl;
    for (auto i : list_x_y[1]){
        std::cout << i << std::endl;
    }
    
    return 0;
}
