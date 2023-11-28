#include <iostream>
#include <vector>

class Nd_vec {
public:
    Nd_vec() : dim(0) {}
    Nd_vec(int d) : dim(d), data(std::vector<int>(d)) {}
    ~Nd_vec() {}
    int dimension() const { return dim; }
    void print(std::ostream& os) const {
        os << "(";
        for (int i = 0; i < dim; i++) {
            os << data[i];
            if (i < dim - 1) os << ", ";
        }
        os << ")";
    }
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
    std::cout << "Contents of v1: ";
    v1.print(std::cout);
    std::cout << std::endl;

    Nd_vec v2(3);
    std::cout << "Dimension of v2 is " << v2.dimension() << std::endl;
    std::cout << "Contents of v2: ";
    v2.print(std::cout);
    std::cout << std::endl;

    // Uncomment the following lines to see compilation errors
    // Nd_vec v3(v2);
    // Nd_vec v4 = v2;

    return 0;
}