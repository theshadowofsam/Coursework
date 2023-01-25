/*
Samuel Lee
*/
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using std::vector;

bool recSearch(int idx, vector<vector<int>> &adj, vector<bool> &localVisited,
               vector<bool> &bigVisited) {
    if (adj[idx].size() == 0) {
        return false;
    } else {
        localVisited[idx] = true;
        bigVisited[idx] = true;
        for (size_t i = 0; i < adj[idx].size(); i++) {
            if (localVisited[adj[idx][i]]) {
                return true;
            } else {
                bool bad =
                    recSearch(adj[idx][i], adj, localVisited, bigVisited);
                if (bad) {
                    return true;
                }
            }
        }
        localVisited[idx] = false;
        return false;
    }
}

int acyclic(vector<vector<int>> &adj, vector<bool> &visited) {
    for (size_t i = 0; i < adj.size(); i++) {
        if (visited[i]) {
            continue;
        }
        vector<bool> blank(visited.size(), false);
        if (recSearch(i, adj, blank, visited)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<bool> visited(n, false);
    // vector<bool> base(n, false);
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj, visited);
}