/*
Samuel Lee
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::tuple;
using std::vector;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

tuple<long long int, long long int> MinAndMax(int i, int j, auto& M, auto& m,
                                              auto& exp, auto& ops) {
    long long int minimum = 9223372036854775807;
    long long int maximum = -9223372036854775807;
    for (size_t k = i; k < j; k++) {
        long long int a = eval(M[i][k], M[k + 1][j], ops[k]);
        long long int b = eval(M[i][k], m[k + 1][j], ops[k]);
        long long int c = eval(m[i][k], M[k + 1][j], ops[k]);
        long long int d = eval(m[i][k], m[k + 1][j], ops[k]);
        minimum = min({minimum, a, b, c, d});
        maximum = max({maximum, a, b, c, d});
    }
    return std::make_tuple(minimum, maximum);
}

long long get_maximum_value(const string& exp) {
    vector<vector<long long int>> minima(
        (exp.size() / 2) + 1, vector<long long int>((exp.size() / 2) + 1, 0));
    vector<vector<long long int>> maxima(
        (exp.size() / 2) + 1, vector<long long int>((exp.size() / 2) + 1, 0));
    vector<char> ops;
    for (size_t i = 0; i < exp.size(); i++) {
        if (i % 2 == 0) {
            minima[i / 2][i / 2] = exp[i] - '0';
            maxima[i / 2][i / 2] = exp[i] - '0';
        } else {
            ops.push_back(exp[i]);
        }
    }

    for (size_t s = 1; s < maxima.size(); s++) {
        for (size_t i = 0; i < maxima.size() - s; i++) {
            int j = i + s;
            auto returns = MinAndMax(i, j, maxima, minima, exp, ops);
            minima[i][j] = std::get<0>(returns);
            maxima[i][j] = std::get<1>(returns);
        }
    }

    /*
    for (size_t i = 0; i < minima.size(); i++) {
        for (size_t j = 0; j < minima[0].size(); j++) {
            std::cout << "[" << minima[j][i] << "] ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (size_t i = 0; i < maxima.size(); i++) {
        for (size_t j = 0; j < maxima[0].size(); j++) {
            std::cout << "[" << maxima[j][i] << "] ";
        }
        std::cout << "\n";
    }
    */

    return maxima[0].back();
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
