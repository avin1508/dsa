#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) {
    int mid = (s + e) / 2;

    int lengthLeft = mid - s + 1;
    int lengthRight = e - mid;

    int *left = new int[lengthLeft];
    int *right = new int[lengthRight];

    int k = s;
    for (int i = 0; i < lengthLeft; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < lengthRight; i++) {
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;  

    while (leftIndex < lengthLeft && rightIndex < lengthRight) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex] = left[leftIndex];
            leftIndex++;
        } else {
            arr[mainArrayIndex] = right[rightIndex];
            rightIndex++;
        }
        mainArrayIndex++;
    }

    while (leftIndex < lengthLeft) {
        arr[mainArrayIndex] = left[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }

    while (rightIndex < lengthRight) {
        arr[mainArrayIndex] = right[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main() {
    int arr[] = {10, 6, 8, 11, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);  
    int s = 0;
    int e = n - 1;

    cout << "Before merge sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, s, e);

    cout << "After merge sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
