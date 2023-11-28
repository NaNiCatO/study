#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person{
    std::string name ;
    int age ;
};

auto extract_names(const std::vector<Person>& person_list){
    std::vector<std::string> result ;
    for (auto& i : person_list){
        result.push_back(i.name);
    }
    return result ;
}

auto extract_age(const std::vector<Person>& person_list){
    std::vector<int> result ;
    for (auto& i : person_list){
            result.push_back(i.age);
    }
    return result ;
}

auto combine_fields(const std::vector<std::string>& name, const std::vector<int>& age){
    std::vector<Person> result ;
    for (int i = 0; i < name.size(); i++){
            result.push_back({name[i],age[i]});
    }
    return result ;
}

int main(){
    std::vector<Person> persons{{"Arm",18},{"Zos",20},{"Peed",23}};
    
    auto ex_name = extract_names(persons);
    for(const auto& i : ex_name){
        std::cout << i << std::endl ;
    }
    std::cout << "*********************" << std::endl;
    
    auto ex_age = extract_age(persons);
    for(const auto& i : ex_age){
        std::cout << i << std::endl ;
    }
    std::cout << "*********************" << std::endl;
    
    auto list_per = combine_fields(ex_name,ex_age);
    for(const auto& i : list_per){
        std::cout << i.name << "\t" << i.age << std::endl ;
    }
}
