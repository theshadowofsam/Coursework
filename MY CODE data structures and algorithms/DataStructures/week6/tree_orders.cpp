/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <vector>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::cin;
using std::cout;
using std::ios_base;
using std::vector;

class TreeOrders {
    int n;
    vector<int> key;
    vector<int> left;
    vector<int> right;
    vector<int> in_order_result;
    vector<int> pre_order_result;
    vector<int> post_order_result;

   public:
    void read() {
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> key[i] >> left[i] >> right[i];
        }
    }

    void rin_order(int i) {
        if (left[i] != -1) {
            rin_order(left[i]);
        }
        in_order_result.push_back(key[i]);
        if (right[i] != -1) {
            rin_order(right[i]);
        }
    }

    vector<int> in_order() {
        rin_order(0);
        return in_order_result;
    }

    void rpre_order(int i) {
        pre_order_result.push_back(key[i]);
        if (left[i] != -1) {
            rpre_order(left[i]);
        }
        if (right[i] != -1) {
            rpre_order(right[i]);
        }
    }

    vector<int> pre_order() {
        rpre_order(0);
        return pre_order_result;
    }

    void rpost_order(int i) {
        if (left[i] != -1) {
            rpost_order(left[i]);
        }
        if (right[i] != -1) {
            rpost_order(right[i]);
        }
        post_order_result.push_back(key[i]);
    }

    vector<int> post_order() {
        rpost_order(0);
        return post_order_result;
    }
};

void print(vector<int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
}

int main_with_large_stack_space() {
    ios_base::sync_with_stdio(0);
    TreeOrders t;
    t.read();
    print(t.in_order());
    print(t.pre_order());
    print(t.post_order());
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
