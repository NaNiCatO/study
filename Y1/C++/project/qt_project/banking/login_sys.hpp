#ifndef LOGIN_SYS_HPP
#define LOGIN_SYS_HPP

#include <string>



class Login_sys {
    public:
        std::string username;

        Login_sys() {}
        ~Login_sys() {}
        void Register(std::string name, std::string pass, std::string t);
        
        std::string select_acc_type();

        void create_all_username(const std::string& username , const std::string& password, const std::string& type);

        bool LoggedIn(const std::string &username);

        std::string check_type(const std::string &username);

}; 



#endif
