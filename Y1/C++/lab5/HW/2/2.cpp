#include <iostream>
#include <string>  
#include <vector>
#include <fstream>
#include <algorithm>


class Picture{
private:
    std::vector<std::string> data;
    size_t width;
    size_t height;
public:
    Picture(std::vector<std::string> pic)
    : data{pic}, width{(*max_element(pic.begin(), pic.end())).length()}, height{pic.size()} {}
    Picture() {}

    auto getdata() const { return data; }
    auto getwidth() const { return width; }
    auto getheight() const { return height; }


    auto hcat(const Picture& x){
        for(auto i : x.getdata()){
            data.push_back(i);
        }
    }

    auto vcat(const Picture& x){
        int c = 0;
        for(auto& i :data){
            for(auto j = i.size(); j < width; j++){
                    i += " " ;
            }
            i += x.data[c];
            c ++;
        }
    }

    auto print() const {
        for(auto& i :data){
            std::cout << i << std::endl;
        }
    }

    auto resize(int w,int h){
        int loop_w; 
        if(h > height){
            for(auto j = 0 ; j < (h - height); j++){
                data.push_back("");
            }
        } else if(h < height){
            for(auto j = 0 ; j < (height - h); j++){
                data.pop_back();
            }
        }
        width = (*max_element(data.begin(), data.end())).length();
        if(w > width){
            for(auto& i :data){
                loop_w = w-i.length();
                for(auto j = 0 ; j < loop_w; j++){
                    i += " " ;
                }
            }
        } else if (w < width){
            for(auto& i :data){
                loop_w = i.length()-w;
                for(auto j = 0 ; j < loop_w; j++){
                    i.pop_back() ;

                }
            }
        }
        height = data.size();
    }
};

int main(){
    std::vector<std::string> data;
    std::string line;
    std::ifstream MyReadFile("data1.txt");
    while (getline(MyReadFile, line)){
        data.push_back(line);
    }
    MyReadFile.close();
    Picture x(data);
    
    data.clear();
    std::ifstream MyReadFile1("data2.txt");
    while (getline(MyReadFile1, line)){
        data.push_back(line);
    }
    Picture y(data);

    x.vcat(y);
    x.print();
    
    y.resize(5,5);
    y.print();
    return 0;
}