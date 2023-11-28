#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

class Hero {
public:
    Hero(std::string name = "Nameless Hero") : name_(name) {}
    virtual ~Hero() {}
    std::string name() const { return name_; }
    virtual std::string greetings() const = 0;
    virtual void read(std::istream& is) { is >> name_; }
    virtual void print(std::ostream& os) const { os << name_; }
protected:
    std::string name_;
};

class Warrior : public Hero {
public:
    Warrior(std::string name = "Nameless Warrior") : Hero(name) {}
    std::string greetings() const override { return "I'm " + name_ + ", I will save the world."; }
    void read(std::istream& is) override { Hero::read(is); }
    void print(std::ostream& os) const override { os << "Warrior: "; Hero::print(os); }
};

class Fighter : public Hero {
public:
    Fighter(std::string name = "Nameless Fighter") : Hero(name) {}
    std::string greetings() const override { return "I'm " + name_ + ", my fists will crush the evil."; }
    void read(std::istream& is) override { Hero::read(is); }
    void print(std::ostream& os) const override { os << "Fighter: "; Hero::print(os); }
};

class Mage : public Hero {
public:
    Mage(std::string name = "Nameless Mage") : Hero(name) {}
    std::string greetings() const override { return "I'm " + name_ + ", I can cook with fire magic."; }
    void read(std::istream& is) override { Hero::read(is); }
    void print(std::ostream& os) const override { os << "Mage: "; Hero::print(os); }
};

int main() {
    using Hero_ptr = std::unique_ptr<Hero>;
    std::vector<Hero_ptr> vec;
    vec.push_back(std::make_unique<Warrior>("Cecil"));
    vec.push_back(std::make_unique<Fighter>());
    vec.push_back(std::make_unique<Mage>("Vivi"));

    for (auto& hero : vec) {
        hero->print(std::cout);
        std::cout << std::endl;
        std::cout << hero->greetings();
        std::cout << std::endl;
    }

    std::ofstream fout("heroes.html");
    fout << "<table>" << std::endl;
    for (auto& hero : vec) {
        fout << "<tr><td>";
        hero->print(fout);
        fout << "</td><td>";
        fout << hero->greetings();
        fout << "</td></tr>" << std::endl;
    }

    return 0;
}