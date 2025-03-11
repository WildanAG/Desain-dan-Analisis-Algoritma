#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int i, j, tmp;
	//Proses Bubble Sort
	for (i=0;i<n;i++) {
		//Proses sorting fase
		for (j = 0; j < n - i - 1; j++) {
			//Proses penukaran
			if (arr[j] < arr[j + 1]) {
				//arr = Array, tmp = data sementara/data sekarang
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int array[100], n, i, j;
	cout << "Masukan banyak elemen: ";
	cin >> n;
	cout << "Masukan nilai: \n";
	for (i = 0; i < n; i++) {
		cin >> array[i];	
	}
	bubbleSort(array, n);
	cout << "Hasil pengurutan dengan algoritma bubblesort:\n";
	for (i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
}
