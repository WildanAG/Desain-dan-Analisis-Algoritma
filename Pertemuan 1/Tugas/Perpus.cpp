#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string array[], int n)
{
	int i, j, tmp;
	for (i=0; i<n; i++) {
		for (j=0; j<n-i-1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j+1]);
			}
		}
	}
}

int main()
{
	int i, n, j;
	string judul[500];
	cout << "====================================" << endl;
	cout << "Masukan jumlah judul buku: ";
	cin >> n;
	cout << "====================================" << endl;
	for(i=0; i<n; i++) {
		cout << "Judul buku ke-" << i+1 << " : ";
		cin >> judul[i];
	}
	bubbleSort(judul, n);
	cout << "Hasil sorting dengan BubbleSort:" << endl;
	cout << "------------------------------------" << endl;
	for (i=0; i<n; i++) {
		cout << i+1 << ". " << judul[i] << endl;
	}
	cout << "------------------------------------" << endl;
	return 0;
}
