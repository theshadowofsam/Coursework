/*
Samuel Lee
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    int temptank = tank;
    int count = 0;
    int i = 1;
    while (i < stops.size() - 1) {
        int diff = stops[i] - stops[i - 1];
        if (diff <= temptank) {
            // cout << "opt1\n";
            temptank -= diff;
            i++;
        } else if (temptank == tank) {
            // cout << "opt2\n";
            return -1;
        } else {
            // cout << "opt3\n";
            temptank = tank;
            count++;
        }

        if (i == stops.size() - 1) {
            diff = stops[i] - stops[i - 1];
            if (temptank >= diff) {
                // cout << "ret1";
                return count;
            } else if (tank >= diff) {
                // cout << diff << "\n";
                // cout << "ret2";
                return count + 1;
            } else {
                // cout << "ret3";
                return -1;
            }
        }
    }
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 1);
    stops.at(0) = 0;
    for (size_t i = 1; i < n + 1; ++i) cin >> stops.at(i);
    stops.push_back(d);
    // for (size_t i = 0; i < stops.size(); i++) {
    //    cout << stops[i] << "\n";
    //}

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
