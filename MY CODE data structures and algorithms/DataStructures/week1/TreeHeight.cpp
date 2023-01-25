/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;
class Node {
   public:
    int key;
    int depth = 1;
    Node *parent;
    std::vector<Node *> children;

    Node() { this->parent = NULL; }

    void setParent(Node *theParent) {
        parent = theParent;
        parent->children.push_back(this);
        if (parent->depth <= depth) {
            parent->inc_depth(depth);
        }
    }

    void inc_depth(int cdepth) {
        if (cdepth < depth - 1) {
            return;
        }
        depth = cdepth + 1;
        if (parent != NULL) {
            parent->inc_depth(depth);
        }
    }
};

int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    int root;
    std::cin >> n;

    std::vector<Node> nodes;
    nodes.resize(n);
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        if (parent_index == -1) {
            root = child_index;
        }
        nodes[child_index].key = child_index;
    }
    Node rootnode = nodes[root];

    /*
    for (auto n : nodes) {
        std::cout << n.depth << "\n";
    }
    */

    std::cout << rootnode.depth;
    return 0;
}

int main(int argc, char **argv) {
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;  // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                std::cerr << "setrlimit returned result = " << result
                          << std::endl;
            }
        }
    }

#endif
    return main_with_large_stack_space();
}