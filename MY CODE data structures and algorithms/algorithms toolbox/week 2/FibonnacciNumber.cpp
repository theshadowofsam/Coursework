/*
Samuel Lee
*/
#include <iostream>
#include <vector>

unsigned long long int run(auto index) {
    switch (index) {
        case 0:
            return 0;

        case 1:
            return 1;

        default:
            break;
    }
    std::vector<unsigned long long int> v(index + 1);
    v[0] = 0;
    v[1] = 1;
    for (size_t i = 2; i < v.size(); i++) {
        v[i] = v[i - 1] + v[i - 2];
    }

    return v.back();
}

int main() {
    int index;
    std::cin >> index;
    auto result = run(index);
    std::cout << result;
    return 0;
}