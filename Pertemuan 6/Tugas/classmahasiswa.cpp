#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    string nim;
    int umur;
    double ipk;

public:
    void input() {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        cout << "Masukkan Umur: ";
        cin >> umur;
        cout << "Masukkan IPK: ";
        cin >> ipk;
    }

    void tampil() {
        cout << "\n=== Data Mahasiswa ===" << endl;
        cout << "Nama : " << nama << endl;
        cout << "NIM  : " << nim << endl;
        cout << "Umur : " << umur << endl;
        cout << "IPK  : " << ipk << endl;
    }
};

int main() {
    Mahasiswa mhs;
    mhs.input();
    mhs.tampil();
    return 0;
}

