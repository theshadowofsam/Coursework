/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    std::vector<int> mins(n + 1);
    for (int i = 0; i <= n; i++) {
        mins[i] = i - 1;
    }
    mins[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i * 2 <= n) {
            if (mins[i * 2] > mins[i] + 1) {
                mins[i * 2] = mins[i] + 1;
            }
        }
        if (i * 3 <= n) {
            if (mins[i * 3] > mins[i] + 1) {
                mins[i * 3] = mins[i] + 1;
            }
        }
        if (i + 1 <= n) {
            if (mins[i + 1] > mins[i] + 1) {
                mins[i + 1] = mins[i] + 1;
            }
        }
    }

    int current = n;
    int d3i, d2i, m1i;
    while (current != 1) {
        sequence.push_back(current);
        d3i = n;
        d2i = n;
        m1i = n;
        if (current % 3 == 0) {
            d3i = current / 3;
        }
        if (current % 2 == 0) {
            d2i = current / 2;
        }
        if (current - 1 >= 1) {
            m1i = current - 1;
        }
        int min = std::min(std::min(mins[d3i], mins[d2i]), mins[m1i]);
        if (min == mins[d3i]) {
            current = d3i;
        } else if (min == mins[d2i]) {
            current = d2i;
        } else {
            current = m1i;
        }
    }
    sequence.push_back(1);
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}