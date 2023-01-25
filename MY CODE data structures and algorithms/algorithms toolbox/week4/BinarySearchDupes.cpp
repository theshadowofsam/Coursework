/*
Samuel Lee
*/
#include <cassert>
#include <iostream>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size();
    int mid = (left + right) / 2;
    while (true) {
        if (left > right) {
            return -1;
        }
        if (a[mid] == x) {
            break;
        }
        if (a[mid] < x) {
            left = mid + 1;
            mid = (left + right) / 2;
        } else {
            right = mid - 1;
            mid = (left + right) / 2;
        }
    }
    while (a[mid] == x) {
        if (mid == 0) {
            return mid;
        }
        mid--;
    }
    return mid + 1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        // replace with the call to binary_search when implemented
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
