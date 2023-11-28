#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum Genre { fiction, nonfiction, periodical, biography, children };


std::vector<std::string> nametype{"fiction", "nonfiction", "periodical", "biography", "children"};

class Book{
private:
    int copyright_year;
    std::string ISBN = "n-n-n-x";
    std::string title, author;
    bool available = true;
    Genre type ;

public:
    Book(std::string isbn, std::string t, std::string au, Genre ty, int c_year) 
    : ISBN{isbn}, title{t}, author{au}, copyright_year{c_year}, type{ty} {}
    Book() {}
    
    int getyear() const { return copyright_year; }
    std::string getISBN() const { return ISBN; }
    std::string gettitle() const { return title; }
    std::string getauthor() const { return author; }
    bool getChecking() const { return available; }
    Genre getType() const { return type; }

    auto check_in() {available = false;}
    auto check_out() {available = true;}
    auto compare(const Book& x){
        return ISBN == x.getISBN() ;
    }
    auto print() const {
        std::cout << "ISBM : " << ISBN << std::endl << "title : " << title << "\tauthor : " << author << std::endl << "Genre : " << nametype[type] << std::endl << "copyright year : " << copyright_year << std::endl ;
    }

    auto read(std::istream&){
        std::string userInput;
        std::cout << "ISBM : " ; getline(std::cin,ISBN) ;
        std::cout << "title : " ; getline(std::cin,title) ;
        std::cout << "author : " ; getline(std::cin,author) ;
        std::cout << "[fiction, nonfiction, periodical, biography, children]" << std::endl;
        std::cout << "No.Genre : " ; getline(std::cin,userInput) ;
        if (userInput == "fiction"){
            type = fiction ;
        } else if (userInput == "nonfiction"){
            type = nonfiction ;
        } else if (userInput == "periodical"){
            type = periodical ;
        } else if (userInput == "biography"){
            type = biography ;
        } else if (userInput == "children"){
            type = children ;
        }
        std::cout << "copyright year : " ; std::cin >> copyright_year ;
    }
    
};

auto comp_title (const Book& a, const Book& b){
        return a.gettitle() > b.gettitle() ;
}

auto comp_ISBN (const Book& a, const Book& b){
        return a.getISBN() < b.getISBN() ;
}

auto find(const std::vector<Book>& collection,const std::string& key_word){
    for(auto& i : collection){
        if (key_word == i.getISBN() || key_word == i.gettitle()){
            std::cout << "Found! : " << key_word << std::endl ;
            i.print();
        }
    }
}

auto get_list(const std::vector<Book>& collection,const Genre& key_word){
    std::vector<Book> list_book ;
    for(auto& i : collection){
        if (key_word == i.getType()){
            list_book.push_back(i);
        }
    }
    return list_book ;
}

auto sort_title(std::vector<Book>& collection){
    sort(collection.begin(), collection.end(), comp_title);
}

auto sort_ISBN(std::vector<Book>& collection){
    sort(collection.begin(), collection.end(), comp_ISBN);
}

int main(){
        //    ISBN   title author Genre year
    Book a("1-2-3-x","fun","Arm",fiction,2022);
    Book b("4-5-3-x","fast","EDDY",fiction,2022);
    Book x("1-2-3-x","wha","Arm",fiction,2022);
    Book y("3-2-3-x","Sad","Jimmy",periodical,2022);
    Book z("3-2-3-x","XX","EDDY",nonfiction,2022);
    std::vector<Book> collection{a,b,x,y,z};
    
    //1.1
    std::cout << "===================1.1===================" << std::endl ;
    find(collection,"1-2-3-x");
    find(collection,"fun");


    //1.2
    std::cout << "===================1.2===================" << std::endl ;
    auto list = get_list(collection,fiction);
    for (auto& i : list){
        i.print();
    }
    
    //1.3
    std::cout << "===================1.3===================" << std::endl << std::endl;
    std::cout << "===================sort_ISBN===================" << std::endl;
    sort_ISBN(collection);
    for (auto& i : collection){
        i.print();
    }

    std::cout << "===================sort_title===================" << std::endl;
    sort_title(collection);
    for (auto& i : collection){
        i.print();
    }
    return 0 ;
}
