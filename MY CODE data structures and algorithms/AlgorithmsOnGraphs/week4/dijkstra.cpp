/*
Samuel Lee
Note that this isn't actually dijkstra's, but it is similar
It differs in that it doesn't have a well defined region of known and unknown nodes,
and the next processed node isnt necessarily the "cheapest" 
this was just slightly easier and achieved the same thing
This increases time complexity in some cases, because it is not guaranteed that each node is processed only once
Now that i think about it, it would be fairly simple to change this to dijkstra's
*/
#include <iostream>
#include <limits> // seemed to work better than INT_MAX for grading purposes, along with actuallly being a c++ standard as opposed to c
#include <queue>
#include <vector>

using std::queue;
using std::vector;

long long int distance(vector<vector<int>> &adj,
                       vector<vector<unsigned long long>> &cost,
                       vector<unsigned long long> &dist_to, int s, int t) {
    queue<int> q;
    unsigned long long int cost_here = 0;

    q.push(s);

    while (!q.empty()) {
        // seen[q.front()] = true;
        for (size_t i = 0; i < adj[q.front()].size(); i++) {
            if (cost_here + cost[q.front()][i] < dist_to[adj[q.front()][i]]) {
                dist_to[adj[q.front()][i]] = cost_here + cost[q.front()][i];
                q.push(adj[q.front()][i]);
            }
        }
        q.pop();
        if (!q.empty()) {
            cost_here = dist_to[q.front()];
        }
    }

    if (dist_to[t] == std::numeric_limits<unsigned long long>::max()) {
        return -1;
    } else {
        return dist_to[t];
    }
}

int main() {
    int n, m, s, t;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<unsigned long long>> cost(n, vector<unsigned long long>());
    vector<unsigned long long> dist_to(
        n, std::numeric_limits<unsigned long long>::max());
    // vector<bool> seen(n, false);

    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }

    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, dist_to, s, t);
}