#ifndef READ_DATA_HPP
#define READ_DATA_HPP


#include <vector>
#include <map>
#include <string>


class Read_data{
public:
    std::string username ;
    std::string filename ;
    std::map<std::string, std::vector<int>> record;
    
    Read_data(std::string& name) ;
    Read_data() {}

    std::vector<int> get_Balance();
    std::vector<int> get_History();
    double get_limit();

};

#endif