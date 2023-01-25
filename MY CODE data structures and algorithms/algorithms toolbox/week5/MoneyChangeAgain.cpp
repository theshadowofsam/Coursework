/*
Samuel Lee
*/
#include <iostream>
#include <vector>

int get_change(int m) {
    std::vector<int> paths(m + 1);
    for (int i = 0; i <= m; i++) {
        paths[i] = i;
    }
    for (int i = 0; i <= m; i++) {
        if (i + 4 <= m) {
            if (paths[i + 4] > paths[i] + 1) {
                paths[i + 4] = paths[i] + 1;
            }
        }
        if (i + 3 <= m) {
            if (paths[i + 3] > paths[i] + 1) {
                paths[i + 3] = paths[i] + 1;
            }
        }
        if (i + 1 <= m) {
            if (paths[i + 1] > paths[i] + 1) {
                paths[i + 1] = paths[i] + 1;
            }
        }
    }

    return paths[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
