#include <iostream>
using namespace std;

int main() {
    int data[] = {0, 6, 12, 18, 24};
    int n = sizeof(data) / sizeof(data[0]);
    int x;
    int i = 0;
    bool ditemukan = false;
	
	cout << "Data yang tersedia: 0, 6, 12, 18, 24" << endl;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> x;

    while (i < n) {
        if (data[i] == x) {
            ditemukan = true;
            break;
        }
        i++;
    }

    if (ditemukan) {
        cout << "Data ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}
