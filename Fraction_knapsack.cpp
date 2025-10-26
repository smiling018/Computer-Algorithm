#include <iostream>
#include <iomanip>
using namespace std;
void sortByRatio(float w[], float v[], float r[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (r[j] > r[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(r[i], r[maxIdx]);
        swap(w[i], w[maxIdx]);
        swap(v[i], v[maxIdx]);
    }
}
int main() {
    int n;
    float cap;
    cout << "Enter number of items: ";
    cin >> n;
    float w[100], v[100], r[100];    
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }   
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Enter knapsack capacity: ";
    cin >> cap;
    for (int i = 0; i < n; i++) {
        r[i] = v[i] / w[i];
    }
    sortByRatio(w, v, r, n);
    float total = 0.0; 
    float rem = cap; 
    cout << fixed << setprecision(2); 
    for (int i = 0; i < n; i++) {
        if (w[i] <= rem) {
            rem -= w[i];
            total += v[i];
            cout << "Added item " << i + 1
                 << " completely (Weight: " << w[i]
                 << ", Value: " << v[i] << ").\n";
        } else {
            float frac = rem / w[i];
            total += v[i] * frac;
            cout << "Added " << frac * 100 << "% of item " << i + 1
                 << " (Weight: " << w[i]
                 << ", Value: " << v[i] << ").\n";
            rem = 0; 
            break;
        }
    }
    cout << "\nTotal value in knapsack = " << total << endl;
    return 0;
}


Or, 



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int profit, weight;
    double ratio;
};
bool comp(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}
int main() {
    int n;
    cout << "Number of items: ";
    cin >> n;
    int capacity;
    cout << "Bag Capacity: ";
    cin >> capacity;
    vector<Item> items(n);
    cout << "Profit: ";
    for (int i = 0; i < n; i++){
         cin >> items[i].profit;
    }
    cout << "Weight: ";
    for (int i = 0; i < n; i++)
    {
         cin >> items[i].weight;
    }
    for (int i = 0; i < n; i++)
    {
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    sort(items.begin(), items.end(), comp);
    double totalProfit = 0.0;
    int remCap = capacity;
    cout << "\nSelected items (fractional allowed):\n";
    for (int i = 0; i < n; i++) {
        if (remCap == 0)
        {
              break;
        }
        if (items[i].weight <= remCap) {
            remCap -= items[i].weight;
            totalProfit += items[i].profit;
            cout << "Item " << i + 1 << "  100% taken\n";
        } else {
            double fraction = (double)remCap / items[i].weight;
            totalProfit += items[i].profit * fraction;
            cout << "Item " << i + 1 << fraction * 100 << "% taken\n";
            remCap = 0;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}

