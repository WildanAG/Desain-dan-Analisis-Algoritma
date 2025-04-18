#include <iostream> 
using namespace std; 

// Deklarasi class bernama 'contoh'
class contoh {
private:
    int nilai; // Variabel privat untuk menyimpan nilai

public:
    // Constructor: dijalankan saat objek dibuat
    contoh (int n) {
        nilai = n; // Mengisi variabel 'nilai' dengan nilai dari parameter
    }

    // Method untuk mengambil (mengembalikan) nilai
    int getNum() {
        return nilai; // Mengembalikan nilai dari variabel 'nilai'
    }
};

int main() {
    contoh obj(10); // Membuat objek 'obj' dari class 'contoh' dan memberi nilai 10
    cout << "nilai yang diinputi: " << obj.getNum() << endl; // Menampilkan nilai dari objek menggunakan method getNum()

    return 0; // Mengakhiri program
}

