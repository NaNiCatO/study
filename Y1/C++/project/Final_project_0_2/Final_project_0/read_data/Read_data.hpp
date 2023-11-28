#ifndef READ_DATA_HPP
#define READ_DATA_HPP


#include <vector>
#include <map>
#include <string>


class Read_data{
public:
    std::string username ;
    std::string filename_info ;
    std::string filename_data;
    std::string get_password();
    std::map<std::string, std::vector<int>> record;
    int get_notification_number();
    
    
    Read_data(std::string& name) ;
    Read_data() {}

    std::vector<int> get_Balance();
    std::vector<int> get_History();
    double get_limit();
    std::vector<std::string> get_all_username();

    std::vector<double> get_notification();

    

};

#endif