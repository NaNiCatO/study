#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

auto split(std::string m, char d){
    std::vector<std::string> result;
    std::string line;
    std::stringstream stream(m);

    while (std::getline(stream, line, d)){
        result.push_back(line);
    }

    return result;
}

bool compare(std::vector<std::string> x, std::vector<std::string> y){
    return *min_element(x.begin()+1, x.end()) > *min_element(y.begin()+1, y.end());
}

int main(){
    int i = 1;
    std::vector<std::vector<std::string>> list_score;
    std::string myText;
    std::ifstream MyReadFile("score.txt");
    while (std::getline (MyReadFile, myText)) {
        auto list_w = split(myText, ' ');
        list_score.push_back(list_w);
    }
    MyReadFile.close();
    

    std::sort(list_score.begin(), list_score.end(), compare);
    std::cout << "Min Score Rankings\n" ;
    for (const auto& list_value: list_score) {
        std::cout << i << ". " << list_value[0] << "\t"  << *min_element(list_value.begin(), list_value.end()) << std::endl;
        i +=1 ;
    }
    std::cout << std::endl;


    i = 0 ;
    std::vector<std::vector<std::string>> avg_list ;
    std::vector<std::string> temp_list ;
    double sum = 0;
    for (const auto& list_value: list_score) {
        for (auto value = list_value.begin()+1; value != list_value.end(); value++){
            sum += std::stoi(*value) ;
        }
        temp_list.push_back(list_value[0]);
        temp_list.push_back(std::to_string(sum/(list_value.size()-1)));
        avg_list.push_back(temp_list);
        temp_list.clear();
        sum = 0;
    }
    std::sort(avg_list.begin(), avg_list.end(), compare);
    std::cout << "Average Score Rankings\n" ;
    for (const auto& list_value: avg_list) {
        i +=1 ;
        std::cout << i << ". " << list_value[0] << "\t"  << std::stod(list_value[1]) << std::endl;
    }
    return 0 ;
}