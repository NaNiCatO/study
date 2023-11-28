#ifndef FINAL_HPP
#define FINAL_HPP

#include <limits>
#include <algorithm>


#include "svg_gen_balance.hpp"
//#include "print_format_html.hpp"
#include "Read_data.hpp"
//#include "Read_data.cpp"
//#include "login_sys.cpp"
#include "login_sys.hpp"

using namespace std;

// *********************************************  Useful Function *********************************************


void WriteToFileCsv(std::string filename, std::string data) {
    std::fstream fileout;
    fileout.open(filename, std::ios::out | std::ios::app);
    fileout << data << std::endl;
    if (fileout.fail()) {
        std::cerr << "Error writing to file: " << filename << std::endl;
    }
}

bool IsValid(const std::string& Text) { // Check if its not empty and only contains alphabetic characters
    // Check if Text is not empty
    if (Text.empty()) {
        return false;
    }
    // Username is valid
    return true;
}

void gen_graph(const std::string& path_input, const std::string& path_output, std::map<std::string, std::vector<int>>& record){
    std::map<std::string, std::vector<int>> input_data;
    input_data["Balance"] = record["Balance"];
    input_data["History"] = record["History"];
    //html_format(path_output + "_graph.html", input_data);
    generate_balance_graph(path_input, path_output + "_balance_graph.svg");
    generate_history_graph(path_input, path_output + "_history_graph.svg");
}


// *********************************************  User Class *********************************************

class User {
public:
    std::string username;
    Read_data data;
    // edit
    std::map<std::string, std::vector<int>> record;
    User(std::string &name) : username{name} {
        data = Read_data(username);
        record["Balance"] = data.get_Balance();
        record["History"] =  data.get_History();
    }
    User(){}
    ~User(){}




    void deposit();

    void withdraw();

    void transfer();

};


class Limit_User : public User {
private:
    double limiter;
public:
    Limit_User(std::string &name) : User(name) {
        limiter = data.get_limit();
    }
    Limit_User(){}
    ~Limit_User(){}


    void update_limit();
    void limit();

    void withdraw();


    void transfer();
};

#endif
