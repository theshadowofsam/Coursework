/*
Samuel Lee
01/11/2023

this has got to be sooooooo slow
making the edges alone is ~ O((n^2)/2)
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using std::abs;
using std::map;
using std::pair;
using std::vector;

struct edge {
    pair<int, int> node1, node2;
    long double weight;
    edge(int x1, int y1, int x2, int y2) {
        weight = std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
        node1 = std::make_pair(x1, y1);
        node2 = std::make_pair(x2, y2);
    }
};

struct mycomp {
    bool operator()(const edge& a, const edge& b) {
        return a.weight > b.weight;
    }
};

// C O N S U M E
// Puts all the edges of two given nodes trees into the same tree
bool consume(pair<int, int> node1, pair<int, int> node2,
             map<int, map<int, int>>& tree,
             map<int, vector<pair<int, int>>>& trees, int nodes_size) {
    int size1, size2, tree1, tree2;
    tree1 = tree[node1.first][node1.second];
    tree2 = tree[node2.first][node2.second];
    size1 = trees[tree1].size();
    size2 = trees[tree2].size();

    if (size1 > size2) {
        while (!trees[tree2].empty()) {
            trees[tree1].push_back(trees[tree2].back());
            tree[trees[tree2].back().first][trees[tree2].back().second] = tree1;
            trees[tree2].pop_back();
        }
        if (trees[tree1].size() == nodes_size) {
            return true;
        } else {
            return false;
        }

    } else {
        while (!trees[tree1].empty()) {
            trees[tree2].push_back(trees[tree1].back());
            tree[trees[tree1].back().first][trees[tree1].back().second] = tree2;
            trees[tree1].pop_back();
        }
        if (trees[tree2].size() == nodes_size) {
            return true;
        } else {
            return false;
        }
    }
}

long double minimum_distance(vector<pair<int, int>>& nodes,
                             map<int, map<int, int>>& tree) {
    int which_tree;
    long double total = 0;
    pair<int, int> node1, node2;
    vector<edge> edges;
    map<int, vector<pair<int, int>>> trees;
    vector<pair<int, int>> done_nodes;

    // knowing which nodes are in which tree
    for (size_t i = 0; i < nodes.size(); i++) {
        which_tree = tree[nodes[i].first][nodes[i].second];
        if (trees.find(which_tree) == trees.end()) {
            trees[which_tree] = vector<pair<int, int>>();
        }
        trees[which_tree].push_back(
            std::make_pair(nodes[i].first, nodes[i].second));
    }

    // generating all the edges
    done_nodes.push_back(nodes[0]);
    for (size_t i = 1; i < nodes.size(); i++) {
        for (size_t j = 0; j < done_nodes.size(); j++) {
            edges.push_back(edge(nodes[i].first, nodes[i].second,
                                 done_nodes[j].first, done_nodes[j].second));
        }
        done_nodes.push_back(nodes[i]);
    }

    // make a min heap of the edges using mycomp() which min heaps by edge
    // length
    std::make_heap(edges.begin(), edges.end(), mycomp());

    // check the smallest length edge to see if both nodes are in the same tree
    // if not, put them in the same tree and add the edge length to the
    // calculated total, then remove edge from heap
    while (!edges.empty()) {
        std::pop_heap(edges.begin(), edges.end(), mycomp());
        node1 = edges.back().node1;
        node2 = edges.back().node2;
        if (tree[node1.first][node1.second] !=
            tree[node2.first][node2.second]) {
            total += edges.back().weight;
            bool done = consume(node1, node2, tree, trees, nodes.size());
            if (done) {
                return total;
            }
        }
        edges.pop_back();
    }

    return total;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<pair<int, int>> nodes;
    map<int, map<int, int>> tree;
    for (size_t i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        nodes.push_back(std::make_pair(x, y));
        tree[x][y] = i;
    }

    std::cout << std::setprecision(10) << minimum_distance(nodes, tree) << "\n";
    return 0;
}
