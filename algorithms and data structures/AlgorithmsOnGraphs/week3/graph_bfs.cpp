/*
Samuel Lee
*/
#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

int distance(vector<vector<int>> &adj, vector<bool> &seen, int s, int t) {
    queue<int> q;
    int depth = 1;
    q.push(s);
    while (!q.empty()) {
        size_t qs = q.size();
        for (size_t j = 0; j < qs; j++) {
            for (size_t i = 0; i < adj[q.front()].size(); i++) {
                if (adj[q.front()][i] == t) {
                    return depth;
                }
                if (!seen[adj[q.front()][i]]) {
                    q.push(adj[q.front()][i]);
                    seen[adj[q.front()][i]] = true;
                }
            }
            q.pop();
        }
        depth++;
    }
    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<bool> seen(n, false);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, seen, s, t);
}