/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int reach(vector<vector<int>> &adj, vector<bool> &seen, int x, int y) {
    seen[x] = true;
    if (std::find(adj[x].begin(), adj[x].end(), y) != adj[x].end()) {
        return 1;
    } else {
        for (size_t i = 0; i < adj[x].size(); i++) {
            if (seen[adj[x][i]]) {
                continue;
            }
            int result = reach(adj, seen, adj[x][i], y);
            if (result == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<bool> seen(n, false);
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, seen, x - 1, y - 1);
}
