#include <iostream>
#include "login.hpp"

using std::cin;
using std::cout;
using std::endl;

void WriteToFile(std::string filename, std::string data) {
  std::ofstream file(filename);
  if (file.is_open()) {
    file << data;
    file.close();
  } else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}



void Login::Register(){
            std::string type;
            std::string password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            type = select_acc_type();

            // check if all_username.txt exist if not create it
            std::string all_username_file = current_path + "/Name_list/all_username.txt";
            if (!fs::exists(all_username_file)) {
                WriteToFile(all_username_file, "");
            }


            // Check if the username already exists in all_username.txt
            std::ifstream all_username(current_path + "/Name_list/all_username.txt");
            if (all_username.is_open()) {
                std::string line;
                while (std::getline(all_username, line)) {
                if (line == username) {
                    std::cout << "Username already exists. Please choose a different username." << std::endl;
                    all_username.close();
                    return;
                }
                }
                all_username.close();
            } else {
                std::cerr << "Unable to open file: all_username.txt" << std::endl;
                return;
            }

            //Add the username to all_username.txt
            create_all_username(username,password,type);

        }
        

std::string Login::select_acc_type(){
            int choice ;

            if (username == "admin") {
              return "Admin";
            }

            while(true) {
              std::cout << "+=============================+ " << std::endl;
              std::cout << "Please choose an account type: " << std::endl;
              std::cout << "1. No limit" << std::endl;
              std::cout << "2. Limit" << std::endl;
              std::cout << "+=============================+ " << std::endl;

              std::cin >> choice;

              switch (choice) {
                case 1: {
                  return "No limit" ;
                }
                case 2: {

                  return "Limit" ;
                }
                default: {
                          cout << "Invalid choice, please try again." << endl;
                          cin.clear();
                          cin.ignore();
                          cout << endl;
                }
              }
            }

        }


void Login::create_all_username(const std::string& username , const std::string& password, const std::string& type) { // Pass the username as argument
            std::vector<std::string> all_names;
            
            // Read all existing names from all_username.txt
            std::ifstream all_username("Name_list/all_username.txt");
            if (all_username.is_open()) {
                std::string line;
                while (std::getline(all_username, line)) {
                all_names.push_back(line);
                }
                all_username.close();
            } else {
                std::cerr << "Unable to open file: all_username.txt" << std::endl;
            }
            
            // Add the new username to the vector
            all_names.push_back(username);
            
            // Sort the vector in alphabetical order
            std::sort(all_names.begin(), all_names.end());
            
            // Write the sorted names to all_username.txt
            std::ofstream all_username_out("Name_list/all_username.txt", std::ios::out | std::ios::trunc);
            if (all_username_out.is_open()) {
                for (const auto& name : all_names) {
                    all_username_out << name << std::endl;
                }
                all_username_out.close();
            } else {
                std::cerr << "Unable to create all_username.txt" << std::endl;
            }

            // Create a new file for the user
            fs::create_directories(current_path + "/Name_list/" + username);
            
            //Create another file for user if not exist
            std::string filename = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
            if (type=="No limit"){
              WriteToFile(filename, "Password:" + password + "\nType:" + type + "\nNotificationn:0");
            } else if( type== "Limit"){
              WriteToFile(filename, "Password:" + password + "\nType:" + type + "\nNotificationn:0" + "\n: 0");
            } else if (type == "Admin"){
              WriteToFile(filename, "Password:" + password + "\nType:" + type + "\nNotificationn:0");
            }

            //Create another file to store user data
            std::string filename2 = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
            WriteToFile(filename2, "0,0\n");




        }

bool Login::LoggedIn(const std::string &username) {
    std::string input_password;
    std::string password;

    std::cout << "Enter your password: ";
    std::cin >> input_password;

    bool success = false;
    bool nameFound = false; // added flag to check if name is found in all_username.txt

    std::ifstream all_username("Name_list/all_username.txt"); // Open all_username.txt for reading

    //Find existing username
    if (all_username.is_open()) {
        std::string line;
        while (std::getline(all_username, line)) {
        if (line == username) {
            nameFound = true;
            break;
        }
        }
        all_username.close();
    } else {
        std::cerr << "Unable to open file: all_username.txt" << std::endl;
    }

    // Return false if name is not found in all_username.txt
    if (!nameFound) {
        std::cerr << "Name not found in all_username.txt" << std::endl;
        return false;
    }

    std::string filename = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
    std::ifstream file(filename); // Open the user's info file for reading
    std::string user_file_name = filename.substr(filename.find_last_of("/\\") + 1);
    if (file.is_open()) {
        std::getline(file, password);
        int pos = password.find(":");
        password = password.substr(pos + 1);
        file.close();

        std::string user_file = user_file_name.substr(0, user_file_name.find("_"));

        if (user_file == username && input_password == password) {
        std::cout << "Login successful!" << std::endl;
        success = true;
        } else {
        std::cout << "Incorrect username or password. Please try again."
                    << std::endl;
        }
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return success;
}

std::string Login::check_type(const std::string &username){
    std::string type;
    std::string filename = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
    std::ifstream file(filename); // Open the user's info file for reading
    if (file.is_open()) {
        std::getline(file, type);
        std::getline(file, type);
        int pos = type.find(":");
        type = type.substr(pos + 1);
        file.close();
    }
    return type;
}