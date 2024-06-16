#include <iostream>
#include "sort.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 8, 3, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    int arr2[] = {5, 2, 8, 3, 9, 1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    selection_sort(arr2, n2);
    for(int i=0; i<n2; i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    return 0;
}
