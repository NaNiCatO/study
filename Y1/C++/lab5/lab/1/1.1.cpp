#include <iostream>
#include <string>
#include <vector>

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
        std::cout << "ISBM : " << ISBN << std::endl << "title : " << title << "\tauthor : " << author << std::endl << "Genre : " << nametype[type] << std::endl << "copyright year : " << copyright_year ;
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
    
    auto find(const std::vector<Book>& collection){
        for(auto& i : collection){
            if (ISBN == i.getISBN()){
                std::cout << "Title : " << i.gettitle() << std::endl ;
            }
        }
    }
};

int main(){
    Book a("1-2-3-x","fun","Arm",fiction,2022);
    Book x("1-2-3-x","wha","Arm",fiction,2022);
    Book y("3-2-3-x","Sad","Arm",periodical,2022);
    Book z("3-2-3-x","XX","ED",nonfiction,2022);
    std::vector<Book> collect{x,y,z};
    a.find(collect);
    std::cout << std::boolalpha << x.compare(y) << std::endl;
    //x.read(std::cin);
    x.print();

    return 0 ;
}
