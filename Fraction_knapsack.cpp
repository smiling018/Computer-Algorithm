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
