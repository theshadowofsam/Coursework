/*
Samuel Lee
*/
#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    switch (n) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            break;
    }
    std::vector<unsigned long long int> v(n + 1);
    v[0] = 0;
    v[1] = 1;
    for (size_t i = 2; i < v.size(); i++) {
        v[i] = v[i - 1] + v[i - 2] % 10;
    }

    return v.back() % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
