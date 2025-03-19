#include <iostream>
using namespace std;

// Fungsi buat menukar posisi dua elemen di dalam array
void swap(int arr[], int pos1, int pos2) {
    int temp;
    temp = arr[pos1];      // Simpan nilai dari posisi pertama ke variabel sementara
    arr[pos1] = arr[pos2]; // Geser nilai posisi kedua ke posisi pertama
    arr[pos2] = temp;      // Pindahkan nilai yang tadi disimpan ke posisi kedua
}

// Fungsi untuk membagi array menjadi dua bagian (yang lebih kecil dari pivot dan yang lebih besar)
int partition(int arr[], int low, int high, int pivot) {
    int i = low; // Pointer untuk iterasi
    int j = low; // Pointer untuk menempatkan elemen yang lebih kecil dari pivot
    
    while (i <= high) { // Ulangi selama belum mencapai batas akhir array
        if (arr[i] > pivot) { // Kalau elemen lebih besar dari pivot, biarkan saja
            i++;
        } else { 
            swap(arr, i, j); // Kalau lebih kecil atau sama dengan pivot, tukar ke bagian awal
            i++;
            j++; // Geser pointer j supaya siap menampung elemen kecil berikutnya
        }
    }
    return j - 1; // Kembalikan posisi akhir pivot setelah pembagian
}

// Fungsi utama untuk mengurutkan array pakai Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) { // Cek apakah masih ada elemen yang perlu diurutkan
        int pivot = arr[high]; // Pilih elemen terakhir sebagai pivot
        int pos = partition(arr, low, high, pivot); // Bagi array berdasarkan pivot

        quicksort(arr, low, pos - 1); // Urutkan bagian kiri dari pivot
        quicksort(arr, pos + 1, high); // Urutkan bagian kanan dari pivot
    }
}

// Fungsi utama untuk menjalankan program
int main() {
    int n;
    cout << "Tentukan panjang array = ";
    cin >> n; // Input panjang array

    int arr[n]; // Deklarasi array dengan ukuran n
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input elemen-elemen array
    }

    quicksort(arr, 0, n - 1); // Panggil fungsi quicksort buat urutin array

    cout << "Berikutnya adalah array yang telah di sortir = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Cetak array yang sudah diurutkan
    }
}

