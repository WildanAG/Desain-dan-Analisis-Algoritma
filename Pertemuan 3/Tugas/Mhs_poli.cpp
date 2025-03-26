#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
public:
    string nama, status, jurusan, fakultas;
    int umur;

    void inputData() {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan Status (Alumni/Aktif): ";
        getline(cin, status);
        cout << "Masukkan Umur: ";
        cin >> umur;
        cin.ignore();
        cout << "Masukkan Jurusan: ";
        getline(cin, jurusan);
        cout << "Masukkan Fakultas: ";
        getline(cin, fakultas);
    }

    void tampilData() {
        cout << "Data Mahasiswa:\n";
        cout << "Nama     : " << nama << endl;
        cout << "Status   : " << status << endl;
        cout << "Umur     : " << umur << " tahun" << endl;
        cout << "Jurusan  : " << jurusan << endl;
        cout << "Fakultas : " << fakultas << endl;
    }
};

int main() {
    int jumlah;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    cout << "------------------------------------------" << endl;
    cin.ignore();
    
    Mahasiswa mhs[jumlah];
    
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << "\n";
        mhs[i].inputData();
    }

    cout << "\n======================================\n";
    for (int i = 0; i < jumlah; i++) {
        mhs[i].tampilData();
        cout << "--------------------------------------" << endl;
    }
    
    return 0;
}

