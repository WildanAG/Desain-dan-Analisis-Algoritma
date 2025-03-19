#include <iostream>
using namespace std;

void showArray(int arr[], int start, int end) {
    cout << "[";
    for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i != end) cout << ", ";
    }
    cout << "]\n";
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    cout << "Menggabungkan List "; showArray(L, 0, n1 - 1);
    cout << "Menggabungkan List "; showArray(R, 0, n2 - 1);
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    cout << "Menggabungkan List "; showArray(arr, l, r);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        cout << "Pecah List "; showArray(arr, l, m);
        cout << "Pecah List "; showArray(arr, m + 1, r);
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Input jumlah data: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "\nHasil akhir: ";
    showArray(arr, 0, n - 1);
    
    return 0;
}

