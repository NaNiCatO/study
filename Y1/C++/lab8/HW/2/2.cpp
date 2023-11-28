#include <string>
#include <iostream>
#include <memory>
#include <vector>


class Text_base {
private:
    std::string original_text;
    std::string opening_symbol;
    std::string closing_symbol;
public:
    Text_base() = delete;
    Text_base(std::string t) : original_text{t} {}
    Text_base(std::string t, std::string sym) : original_text{t}, opening_symbol{sym}, closing_symbol{sym} {}
    Text_base(std::string t, std::string op_sym, std::string cl_sym) : original_text{t}, opening_symbol{op_sym}, closing_symbol{cl_sym} {}
    ~Text_base() {} // define an empty destructor

    Text_base& operator=(const Text_base& t) {
        this->original_text = t.original_text;
        this->opening_symbol = t.opening_symbol;
        this->closing_symbol = t.closing_symbol;
        return *this;
    }  

    auto get_op_symbol() const { return opening_symbol; }\
    auto get_cl_symbol() const { return closing_symbol; }
    auto get_text() const { return original_text; } // fix: return text

    virtual std::string text() const {
        return original_text;
    }
};

class Quoted_text : public Text_base {
public:
    Quoted_text() = delete;
    Quoted_text(std::string t) : Text_base{t} {} 
    Quoted_text(std::string t, std::string sym) : Text_base{t,sym} {} 
    Quoted_text(std::string t, std::string op_sym, std::string cl_sym) : Text_base{t, op_sym, cl_sym} {} 
    ~Quoted_text() {}

    std::string text() const {
        return get_op_symbol() + get_text() + get_cl_symbol(); 
    }
};

class Crypted_text : public Text_base{
public:
    auto crypt_text(std::string& text){
        std::string result = text;
        for (auto& i : result){
            if('A' <= i && i <= 'Z'){
                i = char('Z' - (i-'A'));
            }
            else if('a' <= i && i <= 'z'){
                
                i = char('z' - (i-'a'));
            }
        }
        return result ;
    }

    Crypted_text() = delete;
    Crypted_text(std::string t) : Text_base{crypt_text(t)} {} 
    Crypted_text(std::string t, std::string sym) : Text_base{crypt_text(t),sym} {} 
    Crypted_text(std::string t, std::string op_sym, std::string cl_sym) : Text_base{crypt_text(t), op_sym, cl_sym} {} 
    ~Crypted_text() {}

};

int main(){
    Text_base q0("Python", "*");
    auto text = q0.text(); // "Python"
    std::cout << text << std::endl;

    Quoted_text q("Python", "*");
    const Text_base& rq = q;
    text = q.text(); // "*Python*"
    std::cout << text << std::endl;
    text = rq.text(); // "*Python*"
    std::cout << text << std::endl;

    q = Quoted_text("Python", "<em>", "</em>");
    text = q.text(); // "<em>Python</em>"
    std::cout << text << std::endl;
    text = rq.text(); // "<em>Python</em>"
    std::cout << text << std::endl;
    
    Crypted_text ct("Abc101");
    const Text_base& rct = ct;
    text = ct.text(); // "Zyx101"
    std::cout << text << std::endl;
    text = rct.text(); // "Zyx101"
    std::cout << text << std::endl;

    ct = Crypted_text{"PYthoN101"};
    text = ct.text(); // "KBgslM101"
    std::cout << text << std::endl;
    text = rct.text(); // "KBgslM101"
    std::cout << text << std::endl;
}


