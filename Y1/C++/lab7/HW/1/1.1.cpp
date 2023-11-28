#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person{
    std::string name ;
    int age ;
};

bool name_ascending(const Person& x, const Person& y){
    return x.name < y.name ;
}

bool name_descending(const Person& x, const Person& y){
    return x.name > y.name ;
}

bool age_ascending(const Person& x, const Person& y){
    return x.age < y.age ;
}

bool age_descending(const Person& x, const Person& y){
    return x.age > y.age ;
}


int main(){
    std::vector<Person> persons{{"Arm",18},{"Zos",20},{"Peed",23}};

    std::cout << "name_ascending" << std::endl;
    sort(persons.begin(),persons.end(),name_ascending);
    for(auto i : persons){
        std::cout << i.name << std::endl;
    }
    std::cout << "*********************" << std::endl;

    std::cout << "name_descending" << std::endl;
    sort(persons.begin(),persons.end(),name_descending);
    for(auto i : persons){
        std::cout << i.name << std::endl;
    }
    std::cout << "*********************" << std::endl;

    std::cout << "age_ascending" << std::endl;
    sort(persons.begin(),persons.end(),age_ascending);
    for(auto i : persons){
        std::cout << i.age << std::endl;
    }
    std::cout << "*********************" << std::endl;

    std::cout << "age_descending" << std::endl;
    sort(persons.begin(),persons.end(),age_descending);
    for(auto i : persons){
        std::cout << i.age << std::endl;
    }
    std::cout << "*********************" << std::endl;
}
