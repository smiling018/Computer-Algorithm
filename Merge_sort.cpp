#include <iostream>
using namespace std;
int main() {
    int n, m, i, j, k;
    cin >> n >> m;
    int arr1[n];
    for (i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    int arr2[m];
    for (i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int p = n + m;
    int arr3[p];

    i = 0; j = 0; k = 0;
 
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    while (j < m) {
        arr3[k++] = arr2[j++];
    }

    cout << "Sorted Array: ";
    for (i = 0; i < p; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}

Or,


#include <iostream>
using namespace std;

int main() {
    int n, m, i, j, k;
    cin >> n >> m;
    int arr1[n];
    for (i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    int arr2[m];
    for (i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int p = n + m;
    int arr3[p];

    i = 0; j = 0; k = 0;
    for (; i < n && j < m; k++) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
    }
   
    for (; i < n; i++, k++) {
        arr3[k] = arr1[i];
    }

    for (; j < m; j++, k++) {
        arr3[k] = arr2[j];
    }

    cout << "Sorted Array: ";
    for (i = 0; i < p; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
