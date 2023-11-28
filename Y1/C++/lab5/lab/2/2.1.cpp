#include <iostream>
#include <string>  
#include <vector>
#include <fstream>
#include <algorithm>




class Picture{
private:
    std::vector<std::string> data;
    int width;
    int height;

public:
    Picture(std::vector<std::string> pic)
    : data{pic}, width{(*max_element(pic.begin(), pic.end())).length()}, height{pic.size()} {}
    Picture() {}

    auto getdata() const { return data; }

    auto print() const {
        for(auto& i :data){
            std::cout << i << std::endl;
        }
    }

    auto hflip() {
        for(auto& i :data){
            for(auto& cha: i){
                if(cha == '\\'){
                    cha = '/';
                } else if(cha == '/'){
                    cha = '\\';
                }
            }
        }
        reverse(data.begin(), data.end());
    }  

    auto vflip(){
        for(auto& i :data){
            for(auto& cha: i){
                if(cha == '\\'){
                    cha = '/';
                } else if(cha == '/'){
                    cha = '\\';
                } else if(cha == '('){
                    cha = ')';
                } else if(cha == ')'){
                    cha = '(';
                } 
            }
            for(auto j = i.size(); j < width; j++){
                i += " " ;
            }
            reverse(i.begin(), i.end());
        }
    }

    auto hcat(Picture& x){
        for(auto i : x.getdata()){
            data.push_back(i);
        }
    }

    auto vcat(Picture& x){
        int c = 0;
        for(auto& i :data){
            for(auto j = i.size(); j < width; j++){
                    i += " " ;
            }
            i += x.data[c];
            c ++;
        }
    }

    auto resize(int w,int h){
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
                for(auto j = 0 ; j < (w-i.length()); j++){
                        i += " " ;
                }
            }
        } else if (w < width){
            for(auto& i :data){
                for(auto j = 0 ; j < (i.length()-w); j++){
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
    
    //x.print();
    //x.hflip();
    //x.vcat(y);
    x.resize(5,5);
    x.print();
    return 0;
}