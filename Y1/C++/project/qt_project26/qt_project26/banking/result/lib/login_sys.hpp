#ifndef LOGIN_SYS_HPP
#define LOGIN_SYS_HPP

#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem ;
std::string current_path = fs::current_path().string();

void WriteToFile(std::string filename, std::string data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

class Login_sys {
    public:
        std::string username;

        Login_sys() {}
        ~Login_sys() {}
        void Register(const std::string& name, const std::string& pass, const std::string& t);
        
        std::string select_acc_type();

        void create_all_username(const std::string& username , const std::string& password, const std::string& type);

        bool LoggedIn(const std::string& username,const std::string& pass);

        std::string check_type(const std::string &username);

}; 



#endif
