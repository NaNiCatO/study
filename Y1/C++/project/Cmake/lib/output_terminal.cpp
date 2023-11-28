#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

#include "output_terminal.hpp"



Output_terminal::Output_terminal(const std::string& name, const std::string& type): username{name}, acc_type{type} {}


void Output_terminal::get_history_record(){
  std::cout << "\n/////////////////////////////////////////////////////" << std::endl;
  std::cout << "Account name : " + username + "\tType : " + acc_type << std::endl;
  std::cout << "=====================================================" << std::endl;
  std::cout << "Your history record is:  |  D / M /date/ time  /year" << std::endl;
  for (int i = 1; i < record["History"].size(); i++){
    if (record["History"][i] >= 0){
      std::cout << std::setw(10) << record["History"][i] << std::setw(13) << "" << "  | " << time_record[i] << std::endl;
    } else {
      std::cout << std::setw(13) << "" << std::setw(10) << record["History"][i] << "  | " << time_record[i] << std::endl;
    }
  }
  std::cout << "Your current balance is: " << record["Balance"].back() << std::endl;
}


void Output_terminal::set_data(const std::map<std::string, std::vector<int>>& data, std::vector<std::string> time){
  this->record = data;
  this->time_record = time;
}