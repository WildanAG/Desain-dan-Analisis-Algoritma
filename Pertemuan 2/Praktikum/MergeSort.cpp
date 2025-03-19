#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua bagian array yang sudah diurutkan
void merge(int arr[], int l, int m, int r)
{
    int x, y, z;
    int n1 = m - l + 1; // Jumlah elemen di bagian kiri
    int n2 = r - m;     // Jumlah elemen di bagian kanan

    int L[n1], R[n2]; // Buat array sementara untuk menampung elemen

    // Copy elemen dari array utama ke array sementara
    for (x = 0; x < n1; x++)
        L[x] = arr[l + x];
    for (y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y];

    // Inisialisasi indeks untuk proses merge
    x = 0; // Indeks untuk array kiri
    y = 0; // Indeks untuk array kanan
    z = l; // Indeks untuk array utama

    // Menggabungkan kembali kedua array yang sudah diurutkan
    while (x < n1 && y < n2) 
    {
        if (L[x] <= R[y]) // Jika elemen kiri lebih kecil atau sama
        {
            arr[z] = L[x]; // Masukkan elemen dari array kiri
            x++;
        }
        else 
        {
            arr[z] = R[y]; // Masukkan elemen dari array kanan
            y++;
        }
        z++; // Geser posisi ke elemen berikutnya
    }

    // Jika masih ada sisa elemen di array kiri, masukkan ke array utama
    while (x < n1) 
    {
        arr[z] = L[x];
        x++;
        z++;
    }

    // Jika masih ada sisa elemen di array kanan, masukkan ke array utama
    while (y < n2) 
    {
        arr[z] = R[y];
        y++;
        z++;
    }
}

// Fungsi utama untuk melakukan Merge Sort
void mergesort(int arr[], int l, int r)
{
    if (l < r) // Jika masih ada lebih dari satu elemen, lanjutkan sorting
    {
        int m = l + (r - l) / 2; // Cari titik tengah

        // Rekursif untuk mengurutkan bagian kiri
        mergesort(arr, l, m);
        // Rekursif untuk mengurutkan bagian kanan
        mergesort(arr, m + 1, r);

        // Gabungkan kedua bagian yang sudah diurutkan
        merge(arr, l, m, r);
    }
}

// Fungsi untuk menampilkan isi array
void show(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << " "; // Cetak setiap elemen
}

int main() {
    int size;
    cout << "Masukan banyak data : ";
    cin >> size; // Input jumlah elemen array

    int* arr = new int[size]; // Alokasi array secara dinamis

    // Input elemen array dari user
    for (int i = 0; i < size; i++)
    {
        cout << "\nMasukkan Data Array ke - " << i << " = ";
        cin >> arr[i];
    }

    // Panggil Merge Sort untuk mengurutkan array
    mergesort(arr, 0, size - 1);

    cout << "\nHasil : ";
    show(arr, size); // Tampilkan hasil pengurutan

    return 0;
}

