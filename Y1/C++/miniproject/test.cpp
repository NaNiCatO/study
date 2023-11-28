#include <string>
#include <iostream>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int find_max(const std::map<std::string, std::vector<int>>& data){
    int max_size = 0;
    for(auto it=data.begin(); it!=data.end(); ++it){
        int temp = (it->second).size();
        if (temp > max_size){
            max_size = temp;
        }
    }
    return max_size;
} 

void default_format(const std::string& path, int type){
    std::ifstream ReadFile("./default_format/message.html");
    std::ofstream MyFile;
    if(type == 1){ 
        MyFile.open(path);
    } else if (type == 2){
        MyFile.open(path, std::ofstream::app);
    }
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

void data_input_format(std::ofstream& MyFile, const std::vector<int>& data, const std::string& name){
    MyFile << "{\n    label: '" << name << "',\n    data: [";
    for(const auto& value: data) {
        MyFile << value << ", ";
    }
    MyFile << "]," << std::endl;
    MyFile << "backgroundColor: ['rgba(255, 26, 104, 0.2)',],\n    borderColor: ['rgba(255, 26, 104, 1)',],\n     borderWidth: 3,\n   }," << std::endl;
}

void html_format(const std::string& path, const std::map<std::string, std::vector<int>>& data){
    std::ofstream MyFile(path);
    default_format(path,1);
    MyFile << "    const data = {\n    labels: [";
    for (int i = 0; i < find_max(data); i++){
        MyFile << "'" << i << "',";
    }
    MyFile << "],\n\n      datasets: [";
    for (auto it=data.begin(); it!=data.end(); ++it){
        data_input_format(MyFile, it->second, it->first);
    }
    MyFile << "]\n};" << std::endl;
    default_format(path,2);
}

int main(){
    std::map<std::string, std::vector<int>> data = {
        {"A", {1, 2, 3}},
        {"B", {4, 5, 6}},
        {"C", {7, 8, 9}}
    };
    std::string path = "output.html";
    html_format(path, data);
    return 0;
}