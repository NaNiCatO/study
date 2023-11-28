#include <limits>
#include <algorithm>
  

#include "svg_gen_balance.hpp"
#include "print_format_html.hpp"
#include "Read_data.hpp"
#include "Read_data.cpp"
#include "login.hpp"
#include "login.cpp"
#include "output_terminal.cpp"
#include "output_terminal.hpp"



// *********************************************  Useful Function ********************************************* 


void WriteToFileCsv(std::string filename, std::string data) {
  std::fstream fileout;
  fileout.open(filename, std::ios::out | std::ios::app);
  fileout << data ; 
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
  html_format(path_output + "_graph.html", input_data);
  generate_balance_graph(path_input, path_output + "_balance_graph.svg");
  generate_history_graph(path_input, path_output + "_history_graph.svg");
}


bool check_username_exist_in_file(std::string filename , std::string name){
  // Check if the username is in all_username.txt
    std::ifstream all_username(filename);
    if (all_username.is_open()) {
      std::string line;
      while (std::getline(all_username, line)) {
      if (line == name) {
        all_username.close();
        return true;
      } 
      }
      return false; 
      all_username.close();
    } else {
      std::cerr << "Unable to open file: " << filename << std::endl;
      return false;
    }
    return false;
}



// *********************************************  User Class *********************************************

class User {
    public:
      std::string username;
      Read_data data;
      Output_terminal out_terminal;
      std::map<std::string, std::vector<int>> record;
      std::vector<std::string> time_record;
      User(std::string &name) : username{name} {
        data = Read_data(username);
        record["Balance"] = data.get_Balance();
        record["History"] =  data.get_History();
        time_record = data.get_Time();
      }
      User(std::string &name, Output_terminal& out) : username{name}, out_terminal{out}{
        data = Read_data(username);
        record["Balance"] = data.get_Balance();
        record["History"] =  data.get_History();
        time_record = data.get_Time();
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
              get_history_record();
              break;
            }
            case 5: {
              cout << "End program." << endl;
              exit = true;
              gen_graph(current_path + "/Name_list/" + username + "/" + username + "_data.csv",current_path + "/Name_list/" + username + "/" + username, record);
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


      void format_action(){
          std::cout << "\n+=======================+ " << std::endl;
          std::cout << "Please choose an option: " << std::endl;
          std::cout << "1. Deposit" << std::endl;
          std::cout << "2. Withdraw" << std::endl;
          std::cout << "3. Transfer" << std::endl;
          std::cout << "4. Get history record and current balance" << std::endl;
          std::cout << "5. Exit" << std::endl;
          std::cout << "+=======================+ " << std::endl;
      }

      void get_history_record(){
        out_terminal.set_data(record, time_record);
        out_terminal.get_history_record();
      }


      void deposit(){
        double last_balance = record["Balance"].back();
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        double new_balance = last_balance + amount;
        record["Balance"].push_back(new_balance);
        record["History"].push_back(amount);
        time_record.push_back(get_current_time());
        cout << "Deposit successful." << endl;
        cout << "Your current balance is: " << new_balance << endl;
        std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
        WriteToFileCsv(filename, std::to_string(amount) + "," + std::to_string(new_balance) + "," + get_current_time());
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
          time_record.push_back(get_current_time());
          cout << "Withdraw successful." << endl;
          cout << "Your current balance is: " << new_balance << endl;
          std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
          WriteToFileCsv(filename,"-" + std::to_string(amount) + "," + std::to_string(new_balance) + "," + get_current_time());
        }
      }
      

      void transfer(){
        std::string receiver;
        double amount;
        cout << "Enter receiver username : ";
        cin >> receiver;
        if (receiver == "admin"){
          cout << "Username not found." << endl;
        } else if (check_username_exist_in_file(current_path + "/Name_list/all_username.txt", receiver)){ // If name is found
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
                time_record.push_back(get_current_time());
                cout << "Transfer successful." << endl;
                cout << "Your current balance is: " << new_balance << endl;
                std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
                WriteToFileCsv(filename,"-" +  std::to_string(amount) + "," + std::to_string(new_balance) + "," + get_current_time());

                // get receiver balance
                User receiver_user(receiver);
                double last_balance2 = receiver_user.record["Balance"].back();
                double new_balance2 = last_balance2 + amount;
                receiver_user.record["Balance"].push_back(new_balance2);
                std::string filename3 = current_path + "/Name_list/" + receiver + "/" + receiver + "_data.csv";
                WriteToFileCsv(filename3, std::to_string(amount) + "," + std::to_string(new_balance2) + "," + get_current_time());
              }
        }
        else {
          cout << "Username not found." << endl;
          return;
        }
      }


      void reset_nontification(){
        std::string filename = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
        std::string pass;
        std::ifstream file(filename); // Open the user's info file for reading
        if (file.is_open()) {
            std::getline(file, pass);
            int pos = pass.find(":");
            pass = pass.substr(pos + 1);
            file.close();
        }
        WriteToFile(filename, "Password:" + pass + "\nType:Limit\nNotification:0");
      }

      void notification(){
        data = Read_data(username);
        std::vector<double> temp = data.get_notification();
        if (temp.size() != 0){
          std::cout << "You have " << temp.size() << " new notification : " << std::endl;
          for (int i = 0; i < temp.size(); i++){
            std::cout << temp[i] << std::endl;
          }
        }else {
          std::cout << "You have no new notification." << std::endl;
        }
      }
};


class Limit_User : public User {
    private:
        double limiter;
    public:
        Limit_User(std::string &name, Output_terminal& out) : User(name, out) {
        limiter = data.get_limit();
        }
        Limit_User(){}
        ~Limit_User(){}


        void Action() {
          int choice = 0; // Initialize choice outside the loop
          bool exit = false;
          while(!exit) {
            format_action();
            std::cout << "6. check current limit" << std::endl;
            std::cout << "7. set limit" << std::endl;
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
                get_history_record();
                break;
              }
              case 5: {
                cout << "End program." << endl;
                exit = true;
                update_limit();
                gen_graph(current_path + "/Name_list/" + username + "/" + username + "_data.csv",current_path + "/Name_list/" + username + "/" + username, record);
                break;
              }
              case 6: {
                get_limit();
                break;
              }
              case 7: {
                set_limit();
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
          WriteToFile(filename, "Password:" + pass + "\nType:Limit\nNotificationn:0 \n:" + std::to_string(limiter));
      }

      void get_limit(){
        std::cout << "Your limit is : " + std::to_string(limiter) << std::endl;
      }

      void set_limit(){
        std::cout << "Please set a limit :" << std::endl;
        std::cin >> limiter;
        if (limiter < 0){
          std::cout << "Invalid limit." << std::endl;
          return;
        }
        else {
          std::cout << "Limit set." << std::endl;
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
          time_record.push_back(get_current_time());
          cout << "Withdraw successful." << endl;
          cout << "Your current balance is: " << new_balance << endl;
          std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
          WriteToFileCsv(filename,"-" +  std::to_string(amount) + "," + std::to_string(new_balance) + "," + get_current_time());
        }
      }


      void transfer(){
        std::string receiver;
        double amount;
        cout << "Enter receiver username : ";
        cin >> receiver;
        // Check if the username is in all_username.txt
        if (receiver == "admin"){
          cout << "Username not found." << endl;
        } else if (check_username_exist_in_file(current_path + "/Name_list/all_username.txt", receiver)){ // If name is found{ // If name is found
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
              time_record.push_back(get_current_time());
              cout << "Transfer successful." << endl;
              cout << "Your current balance is: " << new_balance << endl;
              std::string filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
              WriteToFileCsv(filename,"-" +  std::to_string(amount) + "," + std::to_string(new_balance) + "," + get_current_time());

              // get receiver balance
              User receiver_user(receiver);
              double last_balance2 = receiver_user.record["Balance"].back();
              double new_balance2 = last_balance2 + amount;
              receiver_user.record["Balance"].push_back(new_balance2);
              std::string filename3 = current_path + "/Name_list/" + receiver + "/" + receiver + "_data.csv";
              WriteToFileCsv(filename3, std::to_string(amount) + "," + std::to_string(new_balance2) + "," + get_current_time());
            }
        }
      }

      
};

class admin : public User{
  protected :
    std::vector<std::string> all_username;
    

    // get all username from all_username.txt and store in all_username
    void get_all_username(){
      std::ifstream all_username_file(current_path + "/Name_list/all_username.txt");
      std::string line;
      while (std::getline(all_username_file, line)) {
        all_username.push_back(line);
      }
      all_username_file.close();
    }

  public :
    admin() : User() {
        all_username = data.get_all_username();
      }
    ~admin(){}

    void Action(){
    
      int choice;
      bool exit = false;
      while(!exit){
        std::cout << "+=======================+ " << std::endl;
        std::cout << "Please choose an option: " << std::endl;
        std::cout << "1. View all username in system" << std::endl;
        std::cout << "2. View a user's balance and history" << std::endl;
        std::cout << "3. Change a user's password" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "+=======================+ " << std::endl;
        std::cin >> choice;
        switch (choice){
          case 1:{
            view_all_username();
            break;
          }
          case 2: {
            view_user_record();
            break;
          }
          case 3:{
            change_user_password();
            break;
          }
          case 4:{
            exit = true;
            break;
          }
            
          default:
            cout << "Invalid choice, please try again." << endl;
            cin.clear();
            cin.ignore();
            cout << endl;
        }
      } 

    }

    void view_all_username(){
      std::cout << "////////////////////////"  << std::endl;
      std::cout << "\nUsername in system"  << std::endl;
      for (int i = 0; i < all_username.size(); i++){
        if (all_username[i] == "admin"){
          continue;
        }
        std::cout << (i+1) << " : " << all_username[i] << std::endl;
      }
    }

    

    void view_user_record(){
      std::string username;
      std::cout << "Enter username : ";
      std::cin >> username;
      if (username == "admin"){
        std::cout << "Cannot view this accoutn detail!" << std::endl;
        return;
      }
      
      bool nameFound = false; // added flag to check if name is found in all_username.txt
      std::ifstream all_username(current_path + "/Name_list/all_username.txt");
        if (all_username.is_open()) {
          std::string line;
          while (std::getline(all_username, line)) {
          if (line == username) {
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
      if (!nameFound) {
        std::cerr << "The user does not exist" << std::endl;
        return;
      }

      Login user;
      Read_data data_user = Read_data(username);
      out_terminal = Output_terminal(username, user.check_type(username));
      std::cout << out_terminal.username << "\t"<< out_terminal.acc_type << std::endl;
      record["Balance"] = data_user.get_Balance();
      record["History"] = data_user.get_History();
      time_record = data_user.get_Time();
      get_history_record();

      }

    void change_user_password(){
      std::string username;
      std::cout << "Enter username : "; 
      std::cin >> username;
      if (username == "admin"){
        std::cout << "Cannot change this account password!" << std::endl;
        return;
      }
      bool nameFound = false; // added flag to check if name is found in all_username.txt
      if (check_username_exist_in_file(current_path + "/Name_list/all_username.txt" , username)) {
        std::string new_password;
        std::cout << "Enter new password : ";
        std::cin >> new_password;

        //get data from _info.txt
        std::string filename = current_path + "/Name_list/" + username + "/" + username + "_info.txt";
        std::ifstream file(filename);
        std::string line;
        std::vector<std::string> data;
        while (std::getline(file, line)) {
          data.push_back(line);
        }
        file.close();

        //change password in _info.txt
        data[0] = "Password:" + new_password;

        //delete old _info.txt  
        std::remove(filename.c_str());
        //create new _info.txt
        std::ofstream new_file(filename);
        for (int i = 0; i < data.size(); i++) {
          new_file << data[i] << std::endl;
        }
        std::cout << "Password changed successfully!" << std::endl;
        new_file.close();
      } else {
        std::cerr << "The user does not exist" << std::endl;
        return;
        }
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
          std::cout << "\nWelcome back, " << username << "!" << std::endl;
          std::string type = user.check_type(username);
          Output_terminal out_terminal(username,type);
          if (type == "No limit"){
            User transaction(username, out_terminal);
            transaction.notification(); 
            transaction.Action();
          } else if(type == "Limit") {
            Limit_User transaction(username, out_terminal);
            transaction.notification();
            transaction.Action();
          } else if (type == "Admin"){
            admin transaction;
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