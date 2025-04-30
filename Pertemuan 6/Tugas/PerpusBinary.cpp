#include <iostream>
#include <string>
using namespace std;

int binarySearch(string data[], int size, string target) {
    int kiri = 0;
    int kanan = size - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (data[tengah] == target) {
            return tengah;
        } else if (data[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return -1;
}

int main() {
    string buku[] = {
        "Akuntansi Dasar",
        "Analisis Numerik",
        "Bahasa Indonesia Akademik",
        "Fisika Teknik",
        "Matematika Diskrit",
        "Metodologi Penelitian",
        "Teori Graf"
    };

    int jumlahBuku = sizeof(buku) / sizeof(buku[0]);
    string cariJudul;
	
	cout << "Buku yang tersedia:" << endl;
	cout << "Akuntansi Dasar\n, Analisis Numerik\n, Bahasa Indonesia Akademik\n, Fisika Teknik\n, Matematika Diskrit\n, Metodologi Penelitian\n, Teori Graf" << endl;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, cariJudul);

    int posisi = binarySearch(buku, jumlahBuku, cariJudul);

    if (posisi != -1) {
        cout << "Buku \"" << cariJudul << "\" ditemukan pada rak ke-" << posisi << "." << endl;
    } else {
        cout << "Buku \"" << cariJudul << "\" tidak ditemukan dalam daftar." << endl;
    }

    return 0;
}
