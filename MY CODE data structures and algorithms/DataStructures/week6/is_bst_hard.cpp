/*
Samuel Lee
this differs from is_bst.cpp by allowing
right side references to be equal to the parent
*/
#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    long int key;
    long int left;
    long int right;
    long int max = std::numeric_limits<long int>::max();  // bad
    long int min = std::numeric_limits<long int>::min();  // bad

    Node() : key(0), left(-1), right(-1) {}
    Node(long int key_, long int left_, long int right_)
        : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree) {
    // I should have done a queue of pairs for the max and min
    // instead of adding something to the nodes and modifying them
    // maybe. idk.
    std::queue<Node> que;
    if (!tree.empty()) {
        que.push(tree[0]);
    }
    while (!que.empty()) {
        if (que.front().left != -1) {
            if (tree[que.front().left].key >= que.front().key ||
                tree[que.front().left].key <= que.front().min) {
                return false;
            }
            que.push(tree[que.front().left]);
            que.back().max = que.front().key;
        }
        if (que.front().right != -1) {
            if (tree[que.front().right].key < que.front().key ||
                tree[que.front().right].key > que.front().max) {
                return false;
            }
            que.push(tree[que.front().right]);
            que.back().min = que.front().key - 1;
        }
        que.pop();
    }
    return true;
}

int main() {
    long int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (long int i = 0; i < nodes; ++i) {
        long int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}