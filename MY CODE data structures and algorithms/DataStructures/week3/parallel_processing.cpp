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

class JobQueue {
   private:
    long long int num_workers_;
    vector<long long int> jobs_;
    vector<pair<long long int, long long int>> threads_;
    vector<long long int> assigned_workers_;
    vector<long long int> start_times_;

    void WriteResponse() const {
        for (long long int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        long long int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for (long long int i = 0; i < m; ++i) cin >> jobs_[i];
    }

    void AssignJobs() {
        threads_.push_back(make_pair(-1, -1));
        for (long long int i = 0; i < num_workers_; i++) {
            threads_.push_back(make_pair(i, (long long)0));
        }
        for (long long int i = 0; i < jobs_.size(); i++) {
            /*
            for (size_t i = 1; i < threads_.size(); i++) {
                cout << "(" << threads_[i].first << " " << threads_[i].second
                     << ") ";
            }
            cout << "\n";
            */
            assigned_workers_.push_back(threads_[1].first);
            start_times_.push_back(threads_[1].second);
            threads_[1].second += (long long)jobs_[i];
            SiftDown(1);
        }
    }

    void SiftDown(long long int position) {
        long long int a, b, c;
        a = position;
        b = position * 2;
        c = position * 2 + 1;
        if (b > num_workers_) {
            return;
        }
        if (c > num_workers_) {
            if (threads_[a].second > threads_[b].second ||
                (threads_[a].second == threads_[b].second &&
                 threads_[a].first > threads_[b].first)) {
                swap(threads_[a], threads_[b]);
            }
        } else if (threads_[a].second > threads_[b].second ||
                   threads_[a].second > threads_[c].second) {
            if (threads_[b].second == threads_[c].second) {
                if (threads_[b].first < threads_[c].first) {
                    swap(threads_[a], threads_[b]);
                    SiftDown(b);
                } else {
                    swap(threads_[a], threads_[c]);
                    SiftDown(c);
                }
            } else if (threads_[b].second < threads_[c].second) {
                swap(threads_[a], threads_[b]);
                SiftDown(b);
            } else {
                swap(threads_[a], threads_[c]);
                SiftDown(c);
            }
        } else if (threads_[a].second == threads_[b].second ||
                   threads_[a].second == threads_[c].second) {
            if (threads_[a].first < threads_[b].first &&
                threads_[a].first < threads_[c].first) {
                return;
            } else if (threads_[b].second == threads_[c].second) {
                if (threads_[b].first < threads_[c].first) {
                    swap(threads_[a], threads_[b]);
                    SiftDown(b);
                } else {
                    swap(threads_[a], threads_[c]);
                    SiftDown(c);
                }
            } else {
                if (threads_[b].first < threads_[c].first) {
                    swap(threads_[a], threads_[b]);
                    SiftDown(b);
                } else {
                    swap(threads_[a], threads_[c]);
                    SiftDown(b);
                }
            }
        }
    }

   public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
