#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> test_words{
"switch", "[[noreturn]]",
"if", "[[maybe_unused",
"for", "[[fallthrough]]"
};

std::vector<std::string> extract_attrs(std::vector<std::string>& vec){
    std::vector<std::string> attrs_vec;
    for (auto value = vec.begin(); value != vec.end();){
        if (((*value).substr(0,2) == "[[") && ((*value).substr((*value).size()-2,(*value).size()) == "]]") ){
            attrs_vec.push_back(*value);
            vec.erase(value);
        }
        else{
            ++value ;
        }
    }
    return attrs_vec ;
}

void print_words(const std::vector<std::string>& vec , std::ostream& out){
    for (auto v: vec){
        out << v ;
        if (v != vec[vec.size()-1]){
            out << ", ";
        }
    }
}


int main()
{
    auto non_attrs = test_words;
    auto attrs = extract_attrs(non_attrs);
    std::cout << "Test words: ";
    print_words(test_words, std::cout);
    std::cout << std::endl;
    std::cout << "Attributes: ";
    print_words(attrs, std::cout);
    std::cout << std::endl;
    std::cout << "Non attributes: ";
    print_words(non_attrs, std::cout);
    std::cout << std::endl;
}
