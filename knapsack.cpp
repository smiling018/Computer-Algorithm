#include <iostream>
#include <algorithm>
using namespace std;
int knapsack_dp(int values[], int weights[], int n, int W)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
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
    int W;
    cout << "Enter Capacity : ";
    cin >> W;
    int weights[n], values[n];
    cout << "Enter weights of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter profits of each item:\n";
    for (int i = 0; i < n; i++){
        cin >> values[i];
    }
    int maxProfit = knapsack_dp(values, weights, n, W);
    cout << "Maximum Profit = " << maxProfit << endl;
    return 0;
}
