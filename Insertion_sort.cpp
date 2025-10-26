#include<iostream>

using namespace std;

int main()
{
    int n , i , j;
    cout <<"Number of element : ";
    cin >> n;
    cout << "Elements are : ";
    int arr[n];
    for(i=0 ; i<n  ; i++)
    {
        cin>>arr[i];
    }
    for(i=1; i<n ; i++)
    {
        int temp = arr[i];
        int j;
        for(j=i-1 ; j>=0 ; j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
        cout << "\nIteration - "<<i << "\n";
        for(j=0 ; j<n ; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    cout << "Sorted Array : ";
    for(i=0 ; i<n  ; i++)
    {
        cout<<arr[i] << " ";
    }
    cout << endl;

    return 0;
}
