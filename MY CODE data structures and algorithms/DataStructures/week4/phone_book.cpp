/*
Samuel Lee
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::string;
using std::unordered_map;
using std::vector;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i) std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    unordered_map<int, string> by_number;
    vector<string> result;
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            by_number[queries[i].number] = queries[i].name;
        } else if (queries[i].type == "del") {
            by_number.erase(queries[i].number);
        } else {
            string response = "not found";
            try {
                auto q = by_number.at(queries[i].number);
                response = q;
            } catch (const std::exception& e) {
            }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
