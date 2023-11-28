#include <iostream>

bool is_prime(int n)
{
    if (n == 1 || n % 2 == 0 || (n % 3 == 0 && n > 3))
        return false;

    // check through all numbers of the form i = 6k - 1 and i = 6k + 1
    for (int i = 3; i * i < n; i += 2) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false; // n is divisible by i or i + 2
    }
    return true; // no divisor within [5, n) found
}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter the upper limit: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 2) {
        if (is_prime(i))
            cout << i << endl;
    }
    return 0;
}
