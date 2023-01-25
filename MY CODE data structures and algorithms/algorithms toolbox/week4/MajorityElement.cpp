/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

int get_majority_element(vector<int>& a, int left, int right) {
    map<int, int> counts;
    int target = a.size() / 2;
    for (int b : a) {
        if (counts.find(b) != counts.end()) {
            counts[b] += 1;
        } else {
            counts[b] = 1;
        }
    }
    for (auto& [key, value] : counts) {
        if (value > target) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size())) << '\n';
}