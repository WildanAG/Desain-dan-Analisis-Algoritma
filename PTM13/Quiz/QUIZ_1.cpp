#include <iostream>
#include <algorithm>
using namespace std;

int data[7] = {11, 22, 33, 44, 55, 66, 77};

//fungsi untuk melakukan binary search
int binarysearch(int x, int l, int r) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (data[mid] == x)
            return mid;
        if (data[mid] > x)
            return binarysearch(x, l, mid - 1);
        return binarysearch(x, mid + 1, r);
    }
    return -1;
}

int main() {
    int n = 7;
	cout << "Data yang tersedia" << endl;
	for(int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}

    sort(data, data + n);
    int x;
    cout << "\nMasukkan data yang dicari: ";
    cin >> x;

    int hasil = binarysearch(x, 0, n - 1);
    if (hasil == -1)
        cout << "Data tidak ditemukan" << endl;
    else
        cout << "Data ditemukan pada indeks " << hasil << endl;
    return 0;
}
