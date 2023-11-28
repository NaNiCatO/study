#ifndef LOGIN_HPP
#define LOGIN_HPP



class Login {
    public:
        std::string username;

        void Register();
        
        std::string select_acc_type();

        void create_all_username(const std::string& username , const std::string& password, const std::string& type);

        bool LoggedIn(const std::string &username);

        std::string check_type(const std::string &username);

}; 



#endif