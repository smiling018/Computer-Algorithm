#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid size. Program will exit.\n";
        return 0;
    }
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        cout << "After iteration " << (i + 1) << ": ";
        for (int k = 0; k < n; ++k) cout << arr[k] << " ";
        cout << "\n";
    }
    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}
