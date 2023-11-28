#include <algorithm>
#include <vector>
#include <iostream>

template <class T>
auto median(std::vector<T> vec)
{
    using std::sort;
    using std::vector;
    sort(vec.begin(), vec.end());
    const auto size = vec.size();
    const auto mid = size / 2;
    return (size % 2 == 0)? (vec[mid-1] + vec[mid]) / 2.0 : vec[mid];
}

int main(){
    std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
    std::cout << median(v);
}