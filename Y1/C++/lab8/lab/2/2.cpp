#include <string>
#include <iostream>
#include <memory>
#include <sstream>

class  Hero
{
private:
    std::string name;
public:
    Hero() : name{"Nameless Hero"} {}
    ~Hero() {}
    Hero(std::string n) : name{n} {}
    Hero& operator=(const Hero& t)
    {
        this->name = t.name;
        return *this; 
    }  
    
    Hero(std::istream& iss){
            read(iss);
    }

    
    virtual std::string Name() const{ return name; }

    virtual void print(std::ostream& output) const {
        output << "[" << Name() << " : Hero ]" << std::endl ;
    }

    virtual std::istream& read(std::istream& is){
        char type;
        std::string name;
        is >> type >> name;
        this->name = name;
        return is;
    }

    virtual std::unique_ptr<Hero> clone() const{
        return std::make_unique<Hero>(*this);
    }
};


class  Warrior : public Hero
{
public:
    Warrior() : Hero{"Nameless Warrior"} {}
    Warrior(std::string n) : Hero{n} {}

    auto greetings() const {
        return "I’m " + Name() + ", I will save the world.";
    }

    void print(std::ostream& output) const {
        Hero::print(output);
        output << "[" << Name() << " : Warrior ]" << std::endl ;
    }
};


class  Fighter : public Hero
{
public:
    Fighter() : Hero{"Nameless Fighter"} {}
    Fighter(std::string n) : Hero{n} {}
    virtual std::string greetings()const{
        return "I’m " + Name() + ", my fists will crush the evil.";
    }
    
    void print(std::ostream& output)const{
        Hero::print(output);
        output << "[" << Name() << " : Fighter ]" << std::endl ;
    }
};


class  Mage : public Hero
{
public:
    Mage() : Hero{"Nameless Mage"} {}
    Mage(std::string n) : Hero{n} {}
    auto greetings()const{
        return "I’m " + Name() + ", I can cook with fire magic.";
    }

    void print(std::ostream& output)const{
        Hero::print(output);
        output << "[" << Name() << " : Mage ]" << std::endl ;
    }
};


int main(){
    Warrior warrior1("Cecil");
    Fighter fighter1;
    Mage mage1("Vivi");
    const Hero& hero1 = warrior1;
    const Hero& hero2 = fighter1;
    const Hero& hero3 = mage1;
    // "Cecil"
    auto name = hero1.Name();
    std::cout << name << std::endl;

    name = hero2.Name();
    std::cout << name << std::endl;
    name = hero3.Name();
    // "Vivi"
    std::cout << name << std::endl;
    name = hero3.Name();
    std::cout << "*************************" << std::endl;
    std::cout << warrior1.greetings() << std::endl;
    std::cout << fighter1.greetings() << std::endl;
    std::cout << mage1.greetings() << std::endl;
    std::cout << "*************************" << std::endl;
    warrior1.print(std::cout);

    std::cout << "*************************" << std::endl;
    std::stringstream iss("W Cecil F Ryu M Vivi");
    auto hero5 = std::make_unique<Warrior>(iss);
    auto hero6 = std::make_unique<Fighter>(iss);
    auto hero7 = std::make_unique<Mage>(iss);

    std::cout << "*************************" << std::endl;
    // [Cecil: Warrior]
    hero5->print(std::cout);
    // [Ryu: Fighter]
    hero6->print(std::cout);
    // [Vivi: Mage]
    hero7->print(std::cout);
}
