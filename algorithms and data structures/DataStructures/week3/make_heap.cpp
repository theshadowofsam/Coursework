/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;

class HeapBuilder {
   private:
    vector<int> data_;
    vector<pair<int, int> > swaps_;
    int end_;
    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        /*
        for (size_t i = 1; i < data_.size(); i++) {
            cout << data_[i] << " ";
        }
        cout << "\n";
        */
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        n++;
        data_.resize(n);
        for (int i = 1; i < n; ++i) cin >> data_[i];
        end_ = data_.size() - 1;
    }

    void GenerateSwaps() {
        swaps_.clear();
        for (size_t i = end_ / 2; i > 0; i--) {
            // cout << "DoSwap(" << i << ")\n";
            DoSwap(i);
        }
    }

    void DoSwap(int i) {
        // cout << "i= " << i << "\n";

        if (i * 2 > end_) {
            return;
        }

        else if ((i * 2) + 1 > end_) {
            if (data_[i] > data_[i * 2]) {
                swap(data_[i], data_[i * 2]);
                swaps_.push_back(make_pair(i - 1, i * 2 - 1));
            }
        }

        else if (data_[i] > data_[i * 2] || data_[i] > data_[(i * 2) + 1]) {
            if (data_[i * 2] < data_[(i * 2) + 1]) {
                swap(data_[i], data_[i * 2]);
                swaps_.push_back(make_pair(i - 1, i * 2 - 1));
                DoSwap(i * 2);
            } else {
                swap(data_[i], data_[(i * 2) + 1]);
                swaps_.push_back(make_pair(i - 1, i * 2));
                DoSwap((i * 2) + 1);
            }
        }
    }

   public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
