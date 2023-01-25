/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using std::string;
using std::vector;


int minimum(int a, int b, int c) {
    vector<int> d = {a, b, c};
    std::sort(d.begin(), d.end());
    return d[0];
}

int edit_distance(const string &str1, const string &str2) {
    int x = str1.size();  // i
    int y = str2.size();  // j

    vector<vector<int>> path(x + 2, vector<int>(y + 2));

    for (size_t i = 0; i < x + 1; i++) {
        path[i][0] = i;
    }

    for (size_t j = 0; j < y + 1; j++) {
        path[0][j] = j;
    }

    for (size_t j = 1; j < y + 1; j++) {
        for (size_t i = 1; i < x + 1; i++) {
            int insertion, deletion, mismatch, match;
            insertion = path[i][j - 1] + 1;
            deletion = path[i - 1][j] + 1;
            mismatch = path[i - 1][j - 1] + 1;
            match = path[i - 1][j - 1];
            if (str1[i - 1] == str2[j - 1]) {
                path[i][j] = minimum(insertion, deletion, match);
            } else {
                path[i][j] = minimum(insertion, deletion, mismatch);
            }
        }
    }
    /*
    for (size_t j = 0; j < y + 1; j++) {
        for (size_t i = 0; i < x + 1; i++) {
            std::cout << "[" << path[i][j] << "] ";
        }
        std::cout << "\n";
    }
    */
    return path[x][y];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;    
    return 0;
}
