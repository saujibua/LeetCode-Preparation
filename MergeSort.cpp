#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into a single sorted array
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    //Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    //Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

//Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        //Find the middle point
        int middle = left + (right - left) / 2;

        //Recursively sort the first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        //Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
