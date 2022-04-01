/*
Samuel Lee
*/
#include <iostream>
#include <vector>

int run(int a, int b) {
    int temp;
    for (size_t i = 0; a != 0 && b != 0; i++) {
        if (b == 0) {
            break;
        }

        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    // std::cin >> b;
    int c = run(a, b);
    std::cout << c << '\n';
    return 0;
}
