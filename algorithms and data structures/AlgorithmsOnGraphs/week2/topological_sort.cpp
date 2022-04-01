/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void toposort(int index, vector<vector<int>> &adj, vector<vector<int>> &padj,
              vector<bool> &seen, vector<int> &order) {
    // std::cout << "toposort of " << index << "\n";
    if (adj[index].empty() && !seen[index]) {
        order.push_back(index);
        // std::cout << "pushed back " << index << "\n";
        seen[index] = true;
    }
    for (size_t i = 0; i < adj[index].size(); i++) {
        if (!seen[adj[index][i]]) {
            // std::cout << index << " calling toposort of " << adj[index][i]
            //          << "\n";
            toposort(adj[index][i], adj, padj, seen, order);
        }
    }
    if (!seen[index]) {
        order.push_back(index);
        // std::cout << "pushed back " << index << "\n";
    }
    seen[index] = true;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> padj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        padj[y - 1].push_back(x - 1);
    }
    vector<bool> seen(n, false);
    vector<int> order;
    while (order.size() != adj.size()) {
        for (size_t i = 0; i < adj.size(); i++) {
            toposort(i, adj, padj, seen, order);
        }
    }
    for (int i = order.size() - 1; i >= 0; i--) {
        // std::cout << i << " ";
        std::cout << order[i] + 1 << " ";
    }
}