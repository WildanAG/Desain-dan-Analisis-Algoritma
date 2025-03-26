#include <iostream>
#include <string>
using namespace std;

class Perpustakaan {
private:
    string judul;
    string tanggalP;
    string tanggalK;
    string nama;

public:
    void setNama(string n) {
        nama = n;
    }
    string getNama() {
        return nama;
    }

    void setJudul(string j) {
        judul = j;
    }
    string getJudul() {
        return judul;
    }

    void setTanggalP(string tP) {
        tanggalP = tP;
    }
    string getTanggalP() {
        return tanggalP;
    }

    void setTanggalK(string tK) {
        tanggalK = tK;
    }
    string getTanggalK() {
        return tanggalK;
    }

    void inputData() {
        string temp;
        cout << "\nNama Peminjam: ";
        getline(cin, temp);
        setNama(temp);
        
        cout << "Judul Buku: ";
        getline(cin, temp);
        setJudul(temp);
        
        cout << "Tanggal Peminjaman : ";
        getline(cin, temp);
        setTanggalP(temp);
        
        cout << "Tanggal Pengembalian : ";
        getline(cin, temp);
        setTanggalK(temp);
    }

    void tampilData() {
    	cout << "===============================================" << endl;
        cout << "\nData Peminjaman:\n";
        cout << "Nama Peminjam   : " << getNama() << endl;
        cout << "Judul Buku      : " << getJudul() << endl;
        cout << "Tanggal Pinjam  : " << getTanggalP() << endl;
        cout << "Tanggal Kembali : " << getTanggalK() << endl;
        cout << "===============================================" << endl;
    }
};

int main() {
    char ulang;
    do {
        cout << "=============== PERPUSTAKAAN ===============" << endl;
        cout << "List Buku:" << endl;
        cout << "1. Harry Potter \n2. Monster \n3. Laut Bercerita \n4. One Piece \n5. Atomic Habit" << endl;
        
        Perpustakaan peminjaman;
        peminjaman.inputData();
        peminjaman.tampilData();
        
        cout << "\nIngin memasukkan data lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');
    
    return 0;
}

