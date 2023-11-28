#include <iostream>
#include <vector>


template <typename C>
double** create_ragged_array_new(const C& c, double val) {
    double** outer = new double*[c.size()];

    for (auto i = 0; i < c.size(); ++i) {
        outer[i] = new double[c[i]];
        for (auto j = 0; j < c[i]; ++j) {
            outer[i][j] = val;
        }
    }

    return outer;
}

int main() {
    std::vector<int> dims_new = {2, 5, 3};
    double** rg_arr_new = create_ragged_array_new(dims_new, 1.3);
    for (size_t i = 0; i < dims_new.size(); ++i) {
        for (size_t j = 0; j < dims_new[i]; ++j) {
            std::cout << ' ' << rg_arr_new[i][j];
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
    

}