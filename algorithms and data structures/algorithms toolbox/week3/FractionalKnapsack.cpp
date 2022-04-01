/*
Samuel Lee
*/
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

double get_optimal_value(int capacity, std::vector<int> weights,
                         std::vector<int> values) {
    double value = 0.0;
    double knapsack = 0.0;

    std::vector<std::tuple<double, int, int>> density;
    for (size_t i = 0; i < weights.size(); i++) {
        density.push_back(std::make_tuple((double)values[i] / weights[i],
                                          values[i], weights[i]));
    }
    std::sort(density.begin(), density.end());
    int index = density.size() - 1;
    std::tuple<double, int, int> a;
    double d;
    int v;
    int w;
    // for (auto i : density) {
    //    std::cout << "d= " << std::get<0>(i) << ", v= " << std::get<1>(i)
    //              << ", w= " << std::get<2>(i) << "\n";
    //}

    while (knapsack < capacity) {
        a = density[index];
        d = std::get<0>(a);
        v = std::get<1>(a);
        w = std::get<2>(a);
        double room = capacity - knapsack;
        // std::cout << "d= " << d << "  v= " << v << "  w= " << w
        //          << "\nroom= " << room << "  knapsack=" << knapsack
        //          << "  capacity = " << capacity << "\n";
        if (capacity - knapsack < w) {
            // std::cout << "filled\n";
            value += d * room;
            knapsack += room;
        } else {
            // std::cout << "lighted\n";
            value += v;
            knapsack += w;
        }
        index--;
        if (index == -1) {
            break;
        }
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    std::vector<int> values(n);
    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}