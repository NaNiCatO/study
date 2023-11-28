#include <iostream>



struct Person{
    char name[20];
    int age ;
};

auto extract_names(const Person* person_list){
    const int size = sizeof(*person_list)/sizeof(person_list) ;
    char** result = new char*[size + 1];
    int count = 0 ;
    for (int i = 0; i < size; i++){
        int name_size = sizeof(person_list[i].name);
        result[i] = new char[name_size + 1];
        for(int j = 0; j < name_size; j++){
            result[i][j] = person_list[i].name[j];
        }
        result[i][name_size] = '\0';
    }
    result[size] = nullptr;
    return result;
}

auto extract_age(const Person* person_list){
    const int size = sizeof(*person_list)/sizeof(person_list) ;
    int* result = new int[size+1];
    int count = 0 ;
    for (int i = 0; i < size; i++){
            result[i] = person_list[i].age;
    }
    result[size] = -1;
    return result;
}

auto combine_fields(char** names,int* ages){
    int size = 0;
    for (int i = 0; names[i] != nullptr; i++){
        size++ ;
    }
    Person* result = new Person[size];
    for (int i = 0; i < size; i++) {
        int name_size = sizeof(names[i]);
        for(int j = 0; j < name_size; j++){
            result[i].name[j] = names[i][j];
        }
        result[i].name[name_size] = '\0';
        result[i].age = ages[i];
        }
    return result;
}


int main(){
    Person persons[3] = {{"Arm",18},{"Zos",20},{"Peed",23}};
    
    auto ex_name = extract_names(persons);
    for(int i = 0; ex_name[i] != nullptr; i++){
        std::cout << ex_name[i] << std::endl ;
    }
    std::cout << "*********************" << std::endl;

    auto ex_age = extract_age(persons);
    for(int i = 0; ex_age[i] != -1; i++){
        std::cout << ex_age[i] << std::endl ;
    }
    std::cout << "*********************" << std::endl;

    auto list_per = combine_fields(ex_name,ex_age);
    for(int i = 0; i < 3; i++){
        std::cout <<  list_per[i].name << ", " << list_per[i].age << std::endl;
    }
}