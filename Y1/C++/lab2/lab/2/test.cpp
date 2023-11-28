#include <iostream>


int main()
{
    auto words = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};
        for (const auto& w: words) {
        std::cout << w << std::endl;
    }
}