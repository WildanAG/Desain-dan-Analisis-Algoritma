#include <iostream>
using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArray(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 
    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) { 
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high); 

    printArray(arr, high + 1); 
    return i + 1; 
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pos = partition(arr, low, high);
        quicksort(arr, low, pos - 1); 
        quicksort(arr, pos + 1, high); 
    }
}

int main() {
    int n;
    cout << "Data yang akan di sort : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nQuick Sort :" << endl;
    printArray(arr, n);
    quicksort(arr, 0, n - 1);

    return 0;
}

