/*
Samuel Lee
*/
#include <iostream>
#include <vector>

int get_change(int m) {
    int p = 0;
    int n = 0;
    int d = 0;
    int nr;
    int dr;
    d = m / 10;
    dr = m % 10;
    n = dr / 5;
    nr = dr % 5;
    p = nr;

    return p + n + d;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
