#include <fstream>
#include <sstream>
#include <filesystem>

#include "Read_data.hpp"
namespace fs = std::filesystem ;


std::string current_path = fs::current_path().string();


Read_data::Read_data(std::string& name): username{name} {
    filename_data = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
    filename_info = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
}


std::vector<int> Read_data::get_Balance(){
    std::fstream filein;
    filein.open(filename_data, std::ios::in);
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
    filein.open(filename_data, std::ios::in);
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
    std::ifstream file(filename_info); // Open the user's info file for reading
    if (file.is_open()) {
        std::getline(file, text);
        std::getline(file, text);
        std::getline(file, text);
        std::getline(file, text);

        int pos = text.find(":");
        amount = stod(text.substr(pos + 1));
        file.close();
    }
    return amount;
}

std::vector<std::string> Read_data::get_all_username(){
    std::vector<std::string> all_username;
    std::ifstream file(current_path + "/Name_list/all_username.txt"); // Open all_username.txt for reading
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            all_username.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: all_username.txt" << std::endl;
    }
    return all_username;
}

std::vector<double> Read_data::get_notification(){
    record["History"] = get_History();
    int notification = get_notification_number();

    std::vector<double> notification_list;  
    for (int i = record["History"].size() - notification; i < record["History"].size(); i++){
        notification_list.push_back(record["History"][i]);
    }
    return notification_list;
}

int Read_data::get_notification_number(){
    int notification;
    std::string text;
    std::ifstream file(filename_info); // Open the user's info file for reading
    if (file.is_open()) {
        std::getline(file, text);
        std::getline(file, text);
        std::getline(file, text);

        int pos = text.find(":");
        notification = stod(text.substr(pos + 1));
        file.close();
    }
    return notification;
}

std::string Read_data::get_password(){
    std::string password;
    std::ifstream file(filename_info); // Open the user's info file for reading
    if (file.is_open()) {
        std::getline(file, password);
        int pos = password.find(":");
        password = password.substr(pos + 1);
        file.close();
    }
    return password;
}