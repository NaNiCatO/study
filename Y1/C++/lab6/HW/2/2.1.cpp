#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>



class Picture{
private:
    char** data;
    int width;
    int height;

public:
    Picture(char** pic)
    : data{pic}, width{cal_width(pic)}, height{cal_height(pic)} {}
    Picture() {}
    ~Picture() {}
    
    Picture(const Picture& other) : height(other.height), width(other.width) {
        data = new char*[height];
        for (int i = 0; i < height; i++) {
            data[i] = new char[width + 1];
            strncpy(data[i], other.data[i], width);
            data[i][width] = '\0';
        }
    }

    Picture operator=(const Picture& other){
        if(this != &other){
            for (int i = 0; i < height; i++) {
                delete[] data[i];
            }
            delete[] data;
            this->height = other.height;
            this->width = other.width;
            this->data = new char*[height];
            for (int i = 0; i < height; i++) {
                int width = std::strlen(other.data[i]) + 1;
                this->data[i] = new char[width];
                strcpy(this->data[i], other.data[i]);
            }
        }
        return *this;
    }

    int cal_width(char** data){
            int max_width = 0;
            for (int i = 0; data[i] != nullptr; i++) {
                int width = std::strlen(data[i]);
                if(width > max_width){
                    max_width = width;
                }
            }
            return max_width;
        }

    int cal_height(char** data){
        int size = 0;
        while(data[size] != nullptr){
            size++;
        }
        return size;
    }


    auto getdata() const { return data; }
    auto getwidth() const { return width; }
    auto getheight() const { return height; }

    auto print() const {
        for (int i = 0; i < height; i++) {
            std::cout << data[i] << std::endl;
        }
    }
};

int main(){
    char* data1[] = {
        "     (()__(()",
        "     /       \\",
        "    ( /    \\  \\",
        "     \\ o o    /",
        "     (_()_)__/ \\",
        "    / _,==.____ \\",
        "   (   |--|      )",
        "   /\\_.|__|'-.__/\\_",
        "  / (        /     \\",
        "  \\  \\      (      /",
        "   )  '._____)    /",
        "(((____.--(((____/mrf",
        nullptr
    };
    char* data2[] = {
        " : `.--.' ;              _....,_  ",
        " .'      `.      _..--'\"'       `-._",
        ":          :_.-'\"                  .`.",
        ":  6    6  :                     :  '.;",
        ":          :                      `..';",
        "`: .----. :'                          ;",
        "  `._Y _.'               '           ;",
        "    'U'      .'          `.         ; ",
        "       `:   ;`-..___       `.     .'`.",
        "jgs    _:   :  :    ```\"''\"'``.    `.  `.",
        "     .'     ;..'            .'       `.'`",
        "    `.......'              `........-'`",
        nullptr
    };
    Picture x(data1);
    Picture y(data2);
    y.print();
    x.print();
    return 0;
}