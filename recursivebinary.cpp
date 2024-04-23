#include <iostream>
//#include <vector>

using namespace std;

// Recursive binary search function
int binarySearch( int arr[], int low, int high, int target) {
    if (low<=high) {
        int mid = (low+high) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == target)
            return mid;

        // If the element is smaller than the middle element, then it can only be present in the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        // Else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, high, target);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"Enter data to search"<<endl;
    cin>>target;
    int size = 5;
    int result = binarySearch(arr, 0, size - 1, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;
    return 0;
}