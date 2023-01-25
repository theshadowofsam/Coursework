/*
Samuel Lee
01/25/2023
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string>& patterns) {
    trie t;
    int count = 1;
    int previous;
    t.push_back(map<char, int>());
    for (auto& s : patterns) {
        previous = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (t[previous].find(s[i]) == t[previous].end()) {
                t.push_back(map<char, int>());
                t[previous][s[i]] = count;
                previous = t[previous][s[i]];
                count++;
            } else {
                previous = t[previous][s[i]];
            }
        }
    }

    return t;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);
    for (size_t i = 0; i < t.size(); ++i) {
        for (const auto& j : t[i]) {
            std::cout << i << "->" << j.second << ":" << j.first << "\n";
        }
    }

    return 0;
}