/*
Samuel Lee
*/
#include <iostream>
#include <vector>

long long int run(auto a, auto b) {
    long long int little, big;
    if (a > b) {
        little = b;
        big = a;
    } else {
        little = a;
        big = b;
    }

    for (long long int i = 1; i < a * b; i++) {
        long long int remainder = (i * little) % big;
        if (remainder == 0) {
            return i * little;
        }
    }
    return a * b;
}

int main() {
    long long int a, b;
    std::cin >> a >> b;
    long long int c = run(a, b);
    std::cout << c << '\n';
    return 0;
}
