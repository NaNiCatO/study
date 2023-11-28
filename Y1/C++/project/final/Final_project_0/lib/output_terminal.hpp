#ifndef OUTPUT_DATA_HPP
#define OUTPUT_DATA_HPP

#include <string>
#include <map>
#include <vector>



class Output_terminal {
    public:

        std::string username, acc_type;
        std::map<std::string, std::vector<int>> record;
        std::vector<std::string> time_record ;
        
        Output_terminal(const std::string& name, const std::string& type) ;
        Output_terminal() {}

        void set_data(const std::map<std::string, std::vector<int>>& data, std::vector<std::string> time_record);
        void get_history_record();
};

#endif