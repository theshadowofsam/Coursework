/*
Samuel Lee
*/
#include <iostream>
#include <vector>

using std::vector;

// max weight W
// there are n items to take represented in w<weights>
// n = w.size
//
// vals is a 2D vector<vector<int>>: x-axis is total Weight, y-axis is total
// items; vals[W][n]
//
// W = vals.size()+1
//
// the problem statement simplifies this in that all of the items in w are made
// of gold, so value across all items is constant and does not need to be
// addressed directly in code; value density of all items is 1
int optimal_weight(int W, const vector<int> &w) {
    vector<vector<int>> vals(W + 1, vector<int>(w.size() + 1));
    for (size_t i = 0; i < vals.size(); i++) {
        vals[i][0] = 0;
    }
    for (size_t i = 0; i < w.size() + 1; i++) {
        vals[0][i] = 0;
    }
    for (size_t i = 1; i < w.size() + 1; i++) {
        for (size_t j = 1; j < vals.size(); j++) {
            vals[j][i] = vals[j][i - 1];
            if (w[i - 1] <= j) {
                int val = vals[j - w[i - 1]][i - 1] + w[i - 1];
                if (vals[j][i] < val) {
                    vals[j][i] = val;
                }
            }
        }
    }
    // Visualizes the 2D vector
    /*
    for (size_t j = 0; j < w.size() + 1; j++) {
        for (size_t i = 0; i < vals.size(); i++) {
            std::cout << "[" << vals[i][j] << "]";
        }
        std::cout << "\n";
    }
    */

    return vals[W][w.size()];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
