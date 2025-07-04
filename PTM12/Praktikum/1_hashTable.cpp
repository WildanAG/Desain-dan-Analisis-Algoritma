#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm> // untuk fill_n

using namespace std;

// Ukuran maksimum penyimpanan
int storage[1024];
int i = 0;
int hdt_boundary;

// Fungsi untuk mendapatkan bilangan prima di atas n
int prima_atas(int n) {
    if (n % 2 == 0) {
        n += 1;
    } else {
        n += 2;
    }

    while (true) {
        bool prima = true;
        if (n % 2 == 0) {
            prima = false;
        } else {
            for (int i = 3; i <= sqrt(n); i += 2) {
                if (n % i == 0) {
                    prima = false;
                    break;
                }
            }
        }
        if (prima) return n;
        n += 2;
    }
}

// Fungsi untuk mendapatkan bilangan prima di bawah n
int prima_bawah(int n) {
    if (n <= 2) return 2;

    if (n % 2 == 0) {
        n -= 1;
    } else {
        n -= 2;
    }

    while (n >= 2) {
        bool prima = true;
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                prima = false;
                break;
            }
        }
        if (prima) return n;
        n -= 2;
    }
    return 2;
}

void tambah_linear_probing(int n) {
    bool inserted = false;
    int hash;
    i = 0;
    while (!inserted && (i < hdt_boundary)) {
        hash = (n % hdt_boundary + i) % hdt_boundary;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "======================================" << endl;
}

void tambah_quadratic_probing(int n) {
    bool inserted = false;
    int hash;
    i = 0;
    while (!inserted && (i < hdt_boundary)) {
        hash = (n % hdt_boundary + i * i) % hdt_boundary;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "======================================" << endl;
}

void tambah_double_hashing(int n) {
    cout << "double hashing..." << endl;
    int hash2 = prima_bawah(hdt_boundary);
    bool inserted = false;
    int hash;
    i = 0;
    while (!inserted && (i < hdt_boundary)) {
        hash = (n % hdt_boundary + i * (n % hash2 + 1)) % hdt_boundary;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "======================================" << endl;
}

void cetak(int n) {
    cout << endl;
    cout << "Output program :" << endl;
    for (int a = 0; a < n; ++a) {
        cout << "hash[" << a << "] = " << storage[a] << endl;
    }
    cout << endl;
}

int getRandomNumberFromRange(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    int n, random_number;
    char pilihan;
    string cara;

    // Inisialisasi array storage ke 0
    fill_n(storage, 1024, 0);

    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    cout << "Masukan jumlah data : ";
    cin >> n;

    cout << "Kami menggunakan metode open addressing ada 3 cara, pilih salah satu dengan memilih a,b, atau c :" << endl;
    cout << "a. linear probing" << endl;
    cout << "b. quadratic probing" << endl;
    cout << "c. double hashing" << endl;
    cout << "Pilih a,b, atau c ? ";
    cin >> pilihan;
    cout << endl << endl << "Proses pemasukan data ke hashtable " << endl;

    // Tentukan batas |T|
    hdt_boundary = prima_atas(n);

    for (int a = 0; a < n; ++a) {
        random_number = getRandomNumberFromRange(0, n);

        switch (pilihan) {
            case 'a':
                tambah_linear_probing(random_number);
                cara = "Linear Probing";
                break;
            case 'b':
                tambah_quadratic_probing(random_number);
                cara = "Quadratic Probing";
                break;
            case 'c':
                tambah_double_hashing(random_number);
                cara = "Double Hashing";
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                return 1;
        }
    }

    cetak(hdt_boundary);
    cout << "Diatas adalah hasil output Hashtable dengan cara \"" << cara << "\"" << endl;

    switch (pilihan) {
        case 'a':
            cout << "h(k) = (k mod " << hdt_boundary << ") + i" << endl;
            break;
        case 'b':
            cout << "h(k) = (k mod " << hdt_boundary << ") + i*i" << endl;
            break;
        case 'c': {
            int bawah = prima_bawah(hdt_boundary);
            cout << "h1(k) = k mod " << hdt_boundary << endl;
            cout << "h2(k) = ( h1(k) + i*(k mod " << bawah << " + 1) ) mod " << hdt_boundary << endl;
            break;
        }
    }
    cout << endl;

    return 0;
}

