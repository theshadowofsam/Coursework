/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::string;
using std::unordered_map;
using std::vector;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<vector<string>> elems;
    vector<string> results;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

   public:
    explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) {
        results.push_back(was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        string response = "";
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (size_t i = 0; i < elems[query.ind].size(); i++) {
                response.append(elems[query.ind][i]);
                response.append(" ");
            }
            response.append("\n");
            results.push_back(response);
        } else {
            size_t idx = hash_func(query.s);
            vector<string>::iterator it =
                std::find(elems[idx].begin(), elems[idx].end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems[idx].end());
            else if (query.type == "add") {
                if (it == elems[idx].end())
                    elems[idx].insert(elems[idx].begin(), query.s);
            } else if (query.type == "del") {
                if (it != elems[idx].end()) elems[idx].erase(it);
            }
        }
    }

    void processQueries() {
        elems.resize(bucket_count);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) processQuery(readQuery());
        for (string item : results) {
            std::cout << item;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}