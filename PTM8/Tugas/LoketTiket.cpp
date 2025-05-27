#include <iostream>
using namespace std;

class AntrianTiket {
private:
    static const int MAX = 10;
    string queue[MAX];
    int front, rear;

public:
    AntrianTiket() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void tambahAntrian(const string& nama) {
        if (isFull()) {
            cout << "Antrian penuh. Tidak bisa menambah antrian baru.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = nama;
        cout << "Pembeli " << nama << " telah masuk ke antrian.\n";
    }

    void layaniAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong. Tidak ada yang dilayani.\n";
        } else {
            cout << "Pembeli " << queue[front] << " telah dilayani.\n";
            front++;
        }
    }

    void tampilkanAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
        } else {
            cout << "Daftar antrian:\n";
            for (int i = front; i <= rear; i++) {
                cout << i - front + 1 << ". " << queue[i] << "\n";
            }
        }
    }
};

// Fungsi utama
int main() {
    AntrianTiket loket;
    int pilihan;
    string nama;

    do {
        cout << "\n=== LOKET TIKET BIOSKOP ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pembeli: ";
                cin >> nama;
                loket.tambahAntrian(nama);
                break;
            case 2:
                loket.layaniAntrian();
                break;
            case 3:
                loket.tampilkanAntrian();
                break;
            case 4:
                cout << "Program selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    return 0;
}

