/*
Samuel Lee

the intended solution was bellman-ford
I guess you could say this is sortof a heavily modified bellman-ford

I t h i n k in some cases this has a lesser time complexity
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using std::map;
using std::queue;
using std::vector;

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost) {
    vector<vector<int>> negatives;
    map<int, int> visits;
    for (size_t i = 0; i < cost.size(); i++) {
        for (size_t j = 0; j < cost[i].size(); j++) {
            if (cost[i][j] < 0) {
                negatives.push_back(vector<int>());
                negatives.back().push_back(i);
                negatives.back().push_back(j);
                visits[adj[i][j]] = 0;
            }
        }
    }
    /*
    std::cout << "Here are all the negative edges:\n";
    for (size_t i = 0; i < negatives.size(); i++) {
        std::cout << negatives[i][0] << " " << negatives[i][1] << "\n";
    }
    */

    for (size_t i = 0; i < negatives.size(); i++) {
        vector<long long int> adjusted_cost(cost.size(), 0);
        queue<int> q;
        int looking_at;
        long long int cost_here, cost_to_exchange, cost_ahead;

        // negatives[i] is a vector<int> of size 2, negatives[i][0] points to
        // negatives[i][1] with a negative weight

        q.push(negatives[i][0]);
        while (!q.empty()) {
            cost_here = adjusted_cost[q.front()];  // cost to get to q.front()
            // std::cout << "the cost to get to " << q.front() + 1 << " is "
            // << cost_here << "\n";
            for (size_t j = 0; j < adj[q.front()].size(); j++) {
                looking_at = adj[q.front()][j];
                cost_to_exchange =
                    cost[q.front()][j];  // weight of the edge used to get to
                                         // adj[q.front()][j] from the vertex
                                         // identified by adj[q.front]
                cost_ahead = adjusted_cost[looking_at];  // calculated cost to
                                                         // get to the vertex
                                                         // adj[q.front][j]
                if (visits.find(looking_at) != visits.end()) {
                    if (visits[looking_at] > negatives.size() &&
                        cost_here + cost_to_exchange < cost_ahead) {
                        return 1;
                    }
                    visits[looking_at]++;
                }

                if (looking_at == negatives[i][0] &&
                    cost_to_exchange + cost_here < 0) {
                    /*
                        std::cout << "Found it!\n"
                              << "Our current cost is " << cost_here
                              << " and it costs " << cost_to_exchange
                              << " to get to our starting vertex "
                              << negatives[i][0] + 1 << "\n";
                              */
                    return 1;
                }

                if (cost_ahead == 0 ||
                    cost_here + cost_to_exchange < cost_ahead) {
                    adjusted_cost[looking_at] = cost_here + cost_to_exchange;
                    q.push(adj[q.front()][j]);
                }
            }
            // std::cout << "POP\n";
            q.pop();
        }
    }

    return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cout << negative_cycle(adj, cost);
}
