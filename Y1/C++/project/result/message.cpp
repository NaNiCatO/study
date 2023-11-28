class Read_data{
    public:
      std::string username ;
      std::string filename ;
      std::map<std::string, std::vector<int>> record;
      
      Read_data(std::string& name) : username{name} 
      {
        filename = current_path + "/Name_list/" + username + "/" + username + "_data.csv";
      }


      std::vector<int> get_Balance(){
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
        }
        filein.close();
        return record["Balance"];
      }


      std::vector<int> get_History(){
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
          record["History"].push_back(std::stod(row[0]));
        }
        filein.close();
        return record["History"];
      }
};
