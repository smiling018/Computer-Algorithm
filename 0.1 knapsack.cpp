#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W;

    // Input number of items
    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];

    // Input values
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    // Input weights
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    // Input knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int dp[n + 1][W + 1];

    // DP table creation
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print DP table
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    // Final result
    cout << "\nMaximum value that can be obtained = " << dp[n][W];

    return 0;
}
