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

vector<int> search(string text, trie t) {
    vector<int> results;
    int search, offset;
    for (size_t i = 0; i < text.size(); i++) {
        search = 0;
        offset = 0;
        while (true) {
            // if (t[search].find(text[i + offset]) != t[search].end()) {
            //     search = t[search][text[i + offset]];
            //     offset++;
            // } else if (t[search].find('$') != t[search].end()) {
            //     results.push_back(i);
            //     break;
            // } else {
            //     break;
            // }

            //^This was my initial code and I realize now that I am an idiot and
            // should have checked for the symbol first, but I couldn't come up
            // with any cases that failed. oh well.

            if (t[search].find('$') != t[search].end()) {
                results.push_back(i);
                break;
            } else if (t[search].find(text[i + offset]) != t[search].end()) {
                search = t[search][text[i + offset]];
                offset++;
            } else {
                break;
            }
        }
    }

    return results;
}

int main() {
    size_t n;
    string text;
    vector<string> patterns;

    std::cin >> text;
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        s.append("$");
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);

    vector<int> results = search(text, t);

    if (results.size() > 0) {
        for (size_t i = 0; i < results.size() - 1; i++) {
            std::cout << results[i] << " ";
        }
        std::cout << results.back();
    }

    // for (auto&& i : results) {
    //     std::cout << i << " ";
    // }

    return 0;
}