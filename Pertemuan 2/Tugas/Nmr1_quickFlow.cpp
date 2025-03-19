#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[right];
    int i = left, j = right - 1;
    while (i <= j) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    swap(arr[i], arr[right]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    int arr[n];
    cout << "Masukkan elemen: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Array sebelum sorting: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    quickSort(arr, 0, n - 1);
    cout << "Array setelah sorting: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}

