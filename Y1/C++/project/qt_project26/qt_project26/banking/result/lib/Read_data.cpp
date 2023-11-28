#include <fstream>
#include <sstream>
#include <filesystem>

#include "login_sys.hpp"
#include "Read_data.hpp"
namespace fs = std::filesystem ;




Read_data::Read_data(std::string& name): username{name} {
    filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
}


std::vector<int> Read_data::get_Balance(){
    std::fstream filein;
    filein.open(filename, std::ios::in);
    std::string line , temp , words;
    std::vector<std::string> row;
    while (filein >> line){
        row.clear();
        std::stringstream s(line);
        while (getline(s, words, ',')){
            row.push_back(words);
        }
        record["Balance"].push_back(std::stod(row[1]));
    }
    filein.close();
    return record["Balance"];
}


std::vector<int> Read_data::get_History(){
    std::fstream filein;
    filein.open(filename, std::ios::in);
    std::string line , temp , words;
    std::vector<std::string> row;
    while (filein >> line){
        row.clear();
        std::stringstream s(line);
        while (getline(s, words, ',')){
            row.push_back(words);
        }
        record["History"].push_back(std::stod(row[0]));
    }
    filein.close();
    return record["History"];
}


double Read_data::get_limit(){
    double amount;
    std::string text;
    std::ifstream file(filename); // Open the user's info file for reading
    std::string user_file_name = filename.substr(filename.find_last_of("/\\") + 1);
    if (file.is_open()) {
        std::getline(file, text);
        std::getline(file, text);
        std::getline(file, text);
        int pos = text.find(":");
        amount = stod(text.substr(pos + 1));
        file.close();
    }
    return amount;
}
