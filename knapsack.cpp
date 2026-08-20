#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    return dp[W];
}
int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; 
    int n = values.size();
    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value achievable in the Knapsack: " << max_value << endl;
    return 0;
}
