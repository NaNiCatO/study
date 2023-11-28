#include <filesystem>
#include <sstream>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


#include "./gen_graph/svg_gen_balance.hpp"
#include "./gen_graph/print_format_html.hpp"



using std::cin;
using std::cout;
using std::endl;
namespace fs = std::filesystem;

//std::string current_path = "C:\\Users\\bbcom\\Desktop\\Code\\C++\\project\\result";
std::string current_path = fs::current_path().string();



// *********************************************  Useful Function ********************************************* 

void WriteToFile(std::string filename, std::string data) {
  std::ofstream file(filename);
  if (file.is_open()) {
    file << data;
    file.close();
  } else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

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


// *********************************************  User Class *********************************************

class User {
    public:
      std::string username;
      // edit
      std::map<std::string, std::vector<int>> record;
      User(std::string &name) : username{name} {
        record["Balance"];
        record["History"];
        get_balance();
      }
      User(){}
      ~User(){}



      void Action() {
        int choice = 0; // Initialize choice outside the loop
        bool exit = false;
        while(!exit) {
          format_action();
          std::cin >> choice;

          switch (choice) {
            case 1: {
              deposit();
              break;
            }
            case 2: {
              withdraw();
              break;
            }
            case 3: {
              transfer();
              break;
            }
            case 4: {
              cout << "End program." << endl;
              exit = true;
              cout << "Balance" << endl;
              gen_graph(current_path + "/Name_list/" + username + "/" + username + "_data.csv",current_path + "/Name_list/" + username + "/" + username );
              break;
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


      void gen_graph(const std::string& path_input,  const std::string& path_output){
          std::map<std::string, std::vector<int>> input_data;
          input_data["Balance"] = record["Balance"];
          input_data["History"] = record["History"];
          html_format(path_output + "_graph.html", input_data);
          generate_balance_graph(path_input, path_output + "_balance_graph.svg");
          generate_history_graph(path_input, path_output + "_history_graph.svg");
      }


      void format_action(){
          std::cout << "\n+=======================+ " << std::endl;
          std::cout << "Please choose an option: " << std::endl;
          std::cout << "1. Deposit" << std::endl;
          std::cout << "2. Withdraw" << std::endl;
          std::cout << "3. Transfer" << std::endl;
          std::cout << "4. Exit" << std::endl;
          std::cout << "+=======================+ " << std::endl;
      }

      void get_balance(){
        std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
        std::fstream filein;
        filein.open(filename, std::ios::in);
        std::string line , temp , words;
        std::vector<std::string> row;
        while (filein >> line){
          row.clear();
          std::stringstream s(line);
          while (getline(s, words, ',')){
              row.push_back(words);
          }
          record["Balance"].push_back(std::stod(row[1]));
          record["History"].push_back(std::stod(row[0]));
        }
        filein.close();
      }


      void deposit(){
        double last_balance = record["Balance"].back();
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        double new_balance = last_balance + amount;
        record["Balance"].push_back(new_balance);
        record["History"].push_back(amount);
        cout << "Deposit successful." << endl;
        cout << "Your current balance is: " << new_balance << endl;
        std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
        WriteToFileCsv(filename, std::to_string(amount) + "," + std::to_string(new_balance));
      }

      void withdraw(){
        double last_balance = record["Balance"].back();
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > last_balance){
          cout << "Not enough money." << endl;
          return;
        } else {
          double new_balance = last_balance - amount;
          record["Balance"].push_back(new_balance);
          record["History"].push_back((-1) * amount);
          cout << "Withdraw successful." << endl;
          cout << "Your current balance is: " << new_balance << endl;
          std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
          WriteToFileCsv(filename,"-" + std::to_string(amount) + "," + std::to_string(new_balance));
        }

      }
      
      void transfer(){
        std::string receiver;
        double amount;
        cout << "Enter receiver username : ";
        cin >> receiver;
        // Check if the username is in all_username.txt
        bool nameFound = false; // added flag to check if name is found in all_username.txt
        std::ifstream all_username(current_path + "/Name_list/all_username.txt");
          if (all_username.is_open()) {
            std::string line;
            while (std::getline(all_username, line)) {
            if (line == receiver) {
              nameFound = true;
              all_username.close();
              break;
            } 
            }
            all_username.close();
          } else {
            std::cerr << "Unable to open file: all_username.txt" << std::endl;
            return;
        }
        
        // Return false if name is not found in all_username.txt
        if (!nameFound) {
          std::cerr << "Name not found in all_username.txt" << std::endl;
          return;
        }else { // If name is found
        std::cout << "Please Enter the amount to transfer : ";
        cin >> amount;
        double last_balance = record["Balance"].back();
        if (amount > last_balance){
          cout << "Not enough money." << endl;
          return;
        } else {
            double new_balance = last_balance - amount;
            record["Balance"].push_back(new_balance);
            record["History"].push_back((-1) * amount);
            cout << "Transfer successful." << endl;
            cout << "Your current balance is: " << new_balance << endl;
            std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
            WriteToFileCsv(filename,"-" +  std::to_string(amount) + "," + std::to_string(new_balance));

            // get receiver balance
            std::string filename2 = current_path + "/Name_list/" + receiver + "/" + receiver + "_data.csv";
            std::fstream filein;  
            filein.open(filename2, std::ios::in);
            std::string line , temp , words;
            std::vector<std::string> row;
            while (filein >> line){
              row.clear();
              std::stringstream s(line);
              while (getline(s, words, ',')){
                  row.push_back(words);
              }
              record["RecieverBalance"].push_back(std::stod(row[1]));
              record["RecieverHistory"].push_back(std::stod(row[0]));
            }
            filein.close();
            double last_balance2 = record["RecieverBalance"].back();
            double new_balance2 = last_balance2 + amount;
            record["RecieverBalance"].push_back(new_balance2);
            std::string filename3 = current_path + "/Name_list/" + receiver + "/" + receiver + "_data.csv";
            WriteToFileCsv(filename3, std::to_string(amount) + "," + std::to_string(new_balance2));
          }
        }




      }
};

class Limit_User : public User {
    private:
        double limiter;
    public:
        Limit_User(std::string &name) : User(name) {
        limiter = get_limit();
        }
        Limit_User(){}
        ~Limit_User(){}


        double get_limit(){
            double amount;
            std::string text;
            std::string filename = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
            std::ifstream file(filename); // Open the user's info file for reading
            std::string user_file_name = filename.substr(filename.find_last_of("/\\") + 1);
            if (file.is_open()) {
                std::getline(file, text);
                std::getline(file, text);
                std::getline(file, text);
                int pos = text.find(":");
                amount = stod(text.substr(pos + 1));
                file.close();
            }
            return amount;
          }


        void Action() {
          int choice = 0; // Initialize choice outside the loop
          bool exit = false;
          while(!exit) {
            format_action();
            std::cout << "5. set limit" << std::endl;
            std::cout << "+=======================+ " << std::endl;
            std::cin >> choice;

            switch (choice) {
              case 1: {
                deposit();
                break;
              }
              case 2: {
                withdraw();
                break;
              }
              case 3: {
                transfer();
                break;
              }
              case 4: {
                cout << "End program." << endl;
                exit = true;
                update_limit();
                gen_graph(current_path + "/Name_list/" + username + "/" + username + "_data.csv",current_path + "/Name_list/" + username + "/" + username );
                break;
              }
              case 5: {
                limit();
                break;
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

      void update_limit(){
          std::string filename = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
          std::string pass;
          std::ifstream file(filename); // Open the user's info file for reading
          if (file.is_open()) {
              std::getline(file, pass);
              int pos = pass.find(":");
              pass = pass.substr(pos + 1);
              file.close();
          }
          WriteToFile(filename, "Password:" + pass + "\nType:Limit\n:" + std::to_string(limiter));
      }

      void limit(){
        cout << "Please set a limit :" << endl;
        cin >> limiter;
        if (limiter < 0){
          cout << "Invalid limit." << endl;
          return;
        }
        else {
          cout << "Limit set." << endl;
        }
      }


      void withdraw(){
        double last_balance = record["Balance"].back();
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > last_balance){
          cout << "Not enough money." << endl;
          return;
        } else if (amount > limiter && limiter != 0){
          cout << "Over limit, Please enter lower than : " + std::to_string(limiter) << endl;
          return;
        } 
        
        else {
          double new_balance = last_balance - amount;
          record["Balance"].push_back(new_balance);
          record["History"].push_back((-1) * amount);
          cout << "Withdraw successful." << endl;
          cout << "Your current balance is: " << new_balance << endl;
          std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
          WriteToFileCsv(filename,"-" +  std::to_string(amount) + "," + std::to_string(new_balance));
        }
      }


      void transfer(){
        std::string receiver;
        double amount;
        cout << "Enter receiver username : ";
        cin >> receiver;
        // Check if the username is in all_username.txt
        bool nameFound = false; // added flag to check if name is found in all_username.txt
        std::ifstream all_username(current_path + "/Name_list/all_username.txt");
          if (all_username.is_open()) {
            std::string line;
            while (std::getline(all_username, line)) {
            if (line == receiver) {
              nameFound = true;
              all_username.close();
              break;
            } 
            }
            all_username.close();
          } else {
            std::cerr << "Unable to open file: all_username.txt" << std::endl;
            return;
        }
        
        // Return false if name is not found in all_username.txt
        if (!nameFound) {
          std::cerr << "Name not found in all_username.txt" << std::endl;
          return;
        }else { // If name is found
        std::cout << "Please Enter the amount to transfer : ";
        cin >> amount;
        double last_balance = record["Balance"].back();
        if (amount > last_balance){
          cout << "Not enough money." << endl;
          return;
        } else if (amount > limiter && limiter != 0){
          cout << "Over limit, Please enter lower than : " + std::to_string(limiter) << endl;
          return;
        } else{
            double new_balance = last_balance - amount;
            record["Balance"].push_back(new_balance);
            record["History"].push_back((-1) * amount);
            cout << "Transfer successful." << endl;
            cout << "Your current balance is: " << new_balance << endl;
            std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
            WriteToFileCsv(filename,"-" +  std::to_string(amount) + "," + std::to_string(new_balance));

            // get receiver balance
            std::string filename2 = current_path + "/Name_list/" + receiver + "/" + receiver + "_data.csv";
            std::fstream filein;  
            filein.open(filename2, std::ios::in);
            std::string line , temp , words;
            std::vector<std::string> row;
            while (filein >> line){
              row.clear();
              std::stringstream s(line);
              while (getline(s, words, ',')){
                  row.push_back(words);
              }
              record["RecieverBalance"].push_back(std::stod(row[1]));
              record["RecieverHistory"].push_back(std::stod(row[0]));
            }
            filein.close();
            double last_balance2 = record["RecieverBalance"].back();
            double new_balance2 = last_balance2 + amount;
            record["RecieverBalance"].push_back(new_balance2);
            std::string filename3 = current_path + "/Name_list/" + receiver + "/" + receiver + "_data.csv";
            WriteToFileCsv(filename3, std::to_string(amount) + "," + std::to_string(new_balance2));
          }
        }
      }

      
};




// *********************************************  Login Class *********************************************

class Login {
    public:
        std::string username;

        void Register(){
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
        

        std::string select_acc_type(){
            int choice ;

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


        void create_all_username(const std::string& username , const std::string& password, const std::string& type) { // Pass the username as argument
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
              WriteToFile(filename, "Password:" + password + "\nType:" + type);
            } else if( type== "Limit"){
              WriteToFile(filename, "Password:" + password + "\nType:" + type + "\n: 0");
            }

            //Create another file to store user data
            std::string filename2 = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
            WriteToFile(filename2, "0,0\n");




        }

        bool LoggedIn(const std::string &username) {
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

          std::string check_type(const std::string &username){
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

}; 




// *********************************************  Main Function *********************************************


int main() {
    // Check if the Name_list directory exists
    if (!fs::exists(current_path + "/Name_list")) {
        // If it doesn't exist, create it
        fs::create_directory(current_path + "/Name_list");
    }


    int choice = 0; // Initialize choice outside the loop
    bool exit = false;
    Login user;



  while(!exit) {
    std::cout << "+=======================+ " << std::endl;
    std::cout << "Please choose an option: " << std::endl;
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Exit" << std::endl; // Added case 3 for login
    std::cout << "+=======================+ " << std::endl;

    std::cin >> choice;

    switch (choice) {
      case 1: {
        user.Register();

        break;
      }
      case 3: {
            exit = true;
            break;
      }
      case 2: { // Added case 3 for login
        // Get username input and perform validation/sanitization
        std::string username;
        std::cout << "Enter your username: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any leftover newline characters
        std::getline(std::cin, username);

        // Validate and sanitize the input
        if (!IsValid(username)) {
          std::cout << "Invalid username. Exiting..." << std::endl;
          return 1; // or exit the program or take appropriate action
        }

        // Call LoggedIn() function with the validated username
        if (user.LoggedIn(username)) {
          std::cout << "Welcome back, " << username << "!" << std::endl;
          std::string type = user.check_type(username);
          if (type == "No limit"){
            User transaction(username); 
            transaction.Action();
          } else if(type == "Limit") {
            Limit_User transaction(username);
            transaction.Action();
          }

        }
        exit = true;
        break;
      }
      default: {
        cout << "Invalid choice, please try again." << endl;
        cin.clear();
        cin.ignore();
        cout << endl;

      }
    }
  }
 // Repeat until the user chooses to exit

  return 0;
}