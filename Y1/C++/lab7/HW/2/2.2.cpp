#include <iostream>


struct Point{
    double x ;
    double y ;
};

auto create_point_list(const double* list_x, const double* list_y, const int n){
    Point* points = new Point[n];
    for (int i = 0; i < n; i++) {
        points[i].x = list_x[i];
        points[i].y = list_y[i];
    }
    return points;
}

auto split_point_fields(const Point* points, const int n){
    double* list_x = new double[n];
    double* list_y = new double[n];
    for (int i = 0; i < n; i++) {
        list_x[i] = points[i].x;
        list_y[i] = points[i].y;
    }
    double** list = new double*[2];
    list[0] = list_x;
    list[1] = list_y;
    return list;
}


int main(){
    double points_x[4] = {1.2, 1.5, 10, 25.6};
    double points_y[4] = {0.9, 2.5, 3, 4.5};
    
    
    
    Point* point_list = create_point_list(points_x, points_y, 4);
    for (int i = 0; i < 4; i++) {
        std::cout << point_list[i].x<< ", " << point_list[i].y << std::endl;
    }
    
    
    std::cout << "==========list x,y===========" << std::endl;
    auto list_x_y = split_point_fields(point_list, 4);
    for (int i = 0; i < 4; i++) {
        std::cout << list_x_y[0][i] << ", " << list_x_y[1][i] << std::endl;
    }
    return 0;
}