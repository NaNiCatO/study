#ifndef GRAPHGEN_MAIN_HPP
#define GRAPHGEN_MAIN_HPP


#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


int find_max(const std::map<std::string, std::vector<int>>& data){
    int max_size = 0 ;
    int temp ;
    for(auto it=data.begin(); it!=data.end(); ++it){
        temp = (it->second).size();
        if (temp > max_size){
            max_size = temp;
        }
    }
    return max_size;
} 

void default_format(const std::string& path, int type){
    std::ifstream ReadFile("./gen_graph/default_format/message.html");
    std::ofstream MyFile(path, std::ofstream::app);
    std::string text;
    std::string end;
    bool found;
    if (type == 1){
        found = true ;
        end = "    // setup " ;
    } else if (type == 2){
        found = false ;
        end = "</html>" ;
    }
    while (std::getline (ReadFile, text)) {
        if(found){
            MyFile << text << std::endl;
        } else {
            if ("//second phase" == text){
            found = true;
            }
        }
        if (end == text){
            break;
        }
    }
    MyFile.close();
    ReadFile.close();
}


void data_input_format(const std::string& path, const std::vector<int>& data, const std::string& name){
    std::ofstream MyFile(path, std::ofstream::app);
    MyFile << "{\n    label: '"<< name <<"',\n    data: [";
    int c = 0 ;
    for(const auto& value: data) {
        if (c == 0){
            c ++ ;
        } else {
            MyFile << value << ", ";
        }
    }
    MyFile << "]," << std::endl;
    MyFile << "backgroundColor: ['rgba(";
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, 255);
    for (int i = 0; i < 3; i++) {
        MyFile << distr(eng) << ", ";
    }
    MyFile << "0.2)'],\n    borderColor: ['rgba(";
    for (int i = 0; i < 3; i++) {
        MyFile << distr(eng) << ", ";
    }
    MyFile << "1)'],\n     borderWidth: 3,\n   },";
}


void html_format(const std::string& path, const std::map<std::string, std::vector<int>>& data){
    std::ofstream Myfile(path, std::ios::out | std::ios::trunc);
    std::ofstream MyFile(path, std::ofstream::app);
    default_format(path,1);
    MyFile << "    const data = {\n    labels: [" ;
    for (int i = 1; i <= find_max(data); i++){
        MyFile << "'" << i << "',";
    }
    MyFile << "],\n\n      datasets: ["  ;
    MyFile.close();

    for (auto it=data.begin(); it!=data.end(); ++it){
        data_input_format(path, it->second, it->first);
    }
    std::ofstream myFile(path, std::ofstream::app);
    myFile << "]\n};" << std::endl;
    default_format(path,2);
    myFile.close();
}


#endif