#include <limits>
#include <algorithm>
#include "svg_gen_balance.hpp"
#include "Read_data.hpp"
#include "login_sys.hpp"
#include "final.hpp"

using namespace std;

void WriteToFileCsv(std::string filename, std::string data) {
    std::fstream fileout;
    fileout.open(filename, std::ios::out | std::ios::app);
    fileout << data << std::endl;
    if (fileout.fail()) {
        std::cerr << "Error writing to file: " << filename << std::endl;
    }
}

bool IsValid(const std::string& Text) {
    if (Text.empty()) {
        return false;
    }
    return true;
}

void gen_graph(const std::string& path_input, const std::string& path_output, std::map<std::string, std::vector<int>>& record) {
    std::map<std::string, std::vector<int>> input_data;
    input_data["Balance"] = record["Balance"];
    input_data["History"] = record["History"];
    generate_balance_graph(path_input, path_output + "_balance_graph.svg");
    generate_history_graph(path_input, path_output + "_history_graph.svg");
}


void User::deposit(){
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


void User::withdraw(){
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


void User::transfer(){
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




void Limit_User::update_limit(){
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


void Limit_User::limit(){
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


void Limit_User::withdraw(){
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


void Limit_User::transfer(){
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


int main() {
    // Code for the main function
    return 0;
}
