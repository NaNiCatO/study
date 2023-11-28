#include <iostream>
#include <vector>

class Nd_vec {
public:
    Nd_vec() : dim(0) {}
    Nd_vec(int d) : dim(d), data(std::vector<int>(d)) {}
    ~Nd_vec() {}
    int dimension() const { return dim; }
    // copy constructor deleted
    Nd_vec(const Nd_vec& other) = delete;
    // assignment operator deleted
    Nd_vec& operator=(const Nd_vec& other) = delete;
private:
    int dim;
    std::vector<int> data;
};

int main() {
    Nd_vec v1;
    std::cout << "Dimension of v1 is " << v1.dimension() << std::endl;

    Nd_vec v2(3);
    std::cout << "Dimension of v2 is " << v2.dimension() << std::endl;


    return 0;
}



