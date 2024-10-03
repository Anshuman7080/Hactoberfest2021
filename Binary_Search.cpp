
#include <iostream>
#include <algorithm> // For std::sort
using namespace std;

int lin(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; // Key not found
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 1; // Exit if invalid size
    }

    int* arr = new int[n]; // Dynamically allocate array

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    int key;
    cin >> key;

    // Sort the array before performing binary search
    sort(arr, arr + n);

    int index = lin(arr, n, key);
    if (index == -1) {
        cout << "The number you entered is not in the array." << endl;
    } else {
        cout << "The number is found at index: " << index << endl;
    }

    delete[] arr; // Free allocated memory
    return 0;
}
