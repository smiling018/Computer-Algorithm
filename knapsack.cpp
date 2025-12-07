#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack_dp(vector<int> &values, vector<int> &weights, int W)
{
    int n = values.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j],
                               values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n;
    cout << "Number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter weights of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter profits/values of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    int W;
    cout << "Enter Knapsack Capacity W: ";
    cin >> W;

    int maxProfit = knapsack_dp(values, weights, W);

    cout << "Maximum Profit = " << maxProfit << endl;

    return 0;
}
