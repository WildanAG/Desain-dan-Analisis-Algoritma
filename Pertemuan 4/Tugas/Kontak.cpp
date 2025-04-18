#include <iostream>
#include <string>
using namespace std;

class Kontak {
private:
    string nama;
    string nomor;

public:
    void setNama(string n) {
        nama = n;
    }

    void setNomor(string no) {
        nomor = no;
    }

    string getNama() {
        return nama;
    }

    string getNomor() {
        return nomor;
    }
};

int main() {
    Kontak daftar[10];
    string inNama, inNomor;
    char lanjut;
    int i = 0;

    cout << "Masukkan kontak (maksimal 10 kontak)" << endl;
    do {
        if (i >= 10) {
            cout << "Kontak sudah penuh!" << endl;
            break;
        }

        cout << "Masukkan nama kontak ke - " << i + 1 << " : ";
        getline(cin, inNama);
        cout << "Masukkan nomor telepon kontak ke - " << i + 1 << " : ";
        getline(cin, inNomor);

        daftar[i].setNama(inNama);
        daftar[i].setNomor(inNomor);

        cout << "Kontak berhasil ditambahkan\n";
        cout << "Tambahkan kontak lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore(); 
        i++;
    } while (lanjut == 'y' || lanjut == 'Y');
	
	cout << "\nDaftar Kontak:\n";
    for (int j = 0; j < i; j++) {
        cout << "Kontak ke - " << j + 1 << endl;
        cout << "Nama : " << daftar[j].getNama() << endl;
       	cout << "Nomor Telepon : " << daftar[j].getNomor() << endl;
        cout << "===============================\n";
   	}
    return 0;
}

