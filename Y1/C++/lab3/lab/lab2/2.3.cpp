#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> test_words{
"switch", "[[noreturn]]",
"if", "[[maybe_unused",
"for", "[[fallthrough]]"
};

void extract_attrs(const std::vector<std::string> vec,std::vector<std::string>& attrs_vec,std::vector<std::string>& non_attrs_vec){
    non_attrs_vec = vec ;
    for (auto value = non_attrs_vec.begin(); value != non_attrs_vec.end();){
        if (((*value).substr(0,2) == "[[") && ((*value).substr((*value).size()-2,(*value).size()) == "]]") ){
            attrs_vec.push_back(*value);
            non_attrs_vec.erase(value);
        }
        else{
            ++value ;
        }
    }
}

void print_words(std::ostream& out, const std::vector<std::string>& vec){
    char comma = '"';
    out << "{";
    for (auto v: vec){
        out << comma << v ;
        if (v != vec[vec.size()-1]){
            out << comma << ", ";
        }
    }
    out << "}";
}

int main()
{
    std::vector<std::string> attrs, non_attrs;
    extract_attrs(test_words, attrs, non_attrs);
    std::cout << "Test words: ";
    print_words(std::cout, test_words) ;
    std::cout << std::endl;
    std::cout << "Attributes: ";
    print_words(std::cout, attrs) ;
    std::cout << std::endl;
    std::cout << "Non attributes: ";
    print_words(std::cout, non_attrs) ;
}
