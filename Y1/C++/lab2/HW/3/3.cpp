#include <iostream>
#include <string>
#include <random>
#include <fstream>

double map(double x, double in_min, double in_max, double out_min, double out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

bool is_inside(double x, double y){
    double r = 250;
    double a = 250;
    double b = 250;

    if((x - a) * (x - a) + (y - b) * (y - b) <= r * r){
        return true;
    } else {
        return false;
    }
}

std::string circle_tag(double x, double y){
    std::string color;

    if(is_inside(x, y)){
        color = "\"green\"";
    } else {
        color = "\"red\"";
    }

    std::string tag = "\t<circle cx=\"" + std::to_string(x) + "\" cy=\"" + std::to_string(y) + "\" r=\"10\" fill=" + color + " />";
    return tag;
}

int main()
{
    std::fstream file;
    file.open("circle.html", std::ios::out);

    std::streambuf* stream_buffer_file = file.rdbuf();

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist{-1, 1};

    int N;
    std::cout << "Enter the N value: ";
    std::cin >> N;


    std::cout.rdbuf(stream_buffer_file);
    
    std::cout << "<svg width='500' height='500' xmlns='http://www.w3.org/2000/svg'>" << "\n\t<rect width='100%' height='100%' fill='#EEEEEE' />" << "\n\t<circle cx='250' cy='250' r='250'" << "\n\tstroke='black' stroke-width='2' fill='none' />" << "\n\t<circle cx='250' cy='250' r='10' fill='#00FFFF' />" << std::endl;

    for (int i = 1; i <= N; i++)
    {
        double x = map(dist(rng), -1.30, 1.30, 0, 500);
        
        double y = map(dist(rng), -1.30, 1.30, 0, 500);
        
        std::cout << circle_tag(x, y) << std::endl;
    }
    std::cout << "\t</svg>" << std::endl;
    
    file.close();
    return 0;
}