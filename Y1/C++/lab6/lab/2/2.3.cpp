#include <iostream>
#include <vector>

class Nd_vec {
public:
    Nd_vec() : dim(0) {}
    Nd_vec(int d) : dim(d), data(std::vector<int>(d)) {}
    ~Nd_vec() {}
    Nd_vec(const Nd_vec& other) : dim(other.dim), data(other.data) {}
    Nd_vec& operator=(const Nd_vec& other) {
        if (this != &other) {
            dim = other.dim;
            data = other.data;
        }
        return *this;
    }
    int dimension() const { return dim; }
    void print(std::ostream& os) const {
        os << "(";
        for (int i = 0; i < dim; i++) {
            os << data[i];
            if (i < dim - 1) os << ", ";
        }
        os << ")";
    }
    std::vector<int> get_data() const {
        return data;
    }
private:
    int dim;
    std::vector<int> data;
};

Nd_vec add(const Nd_vec& v1, const Nd_vec& v2) {
    int dim = v1.dimension();
    Nd_vec sum(dim);
    for (int i = 0; i < dim; i++) {
        sum.get_data()[i] = v1.get_data()[i] + v2.get_data()[i];
    }
    return sum;
}

int main() {
    Nd_vec v1(3);
    v1.get_data()[0] = 1;
    v1.get_data()[1] = 2;
    v1.get_data()[2] = 3;
    std::cout << "Dimension of v1 is " << v1.dimension() << std::endl;
    std::cout << "Contents of v1: ";
    v1.print(std::cout);
    std::cout << std::endl;

    Nd_vec v2 = v1;
    std::cout << "Dimension of v2 is " << v2.dimension() << std::endl;
    std::cout << "Contents of v2: ";
    v2.print(std::cout);
    std::cout << std::endl;

    Nd_vec v3;
    v3 = v1;
    std::cout << "Dimension of v3 is " << v3.dimension() << std::endl;
    std::cout << "Contents of v3: ";
    v3.print(std::cout);
    std::cout << std::endl;

    Nd_vec v4 = add(v1, v2);
    std::cout << "Dimension of v4 is " << v4.dimension() << std::endl;
    std::cout << "Contents of v4: ";
    v4.print(std::cout);
    std::cout << std::endl;

    return 0;
}
