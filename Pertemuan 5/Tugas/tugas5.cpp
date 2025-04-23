#include <iostream>
#include <string>
using namespace std;

int main () 
{
	int jumlah;
	cout << "Masukan jumlah nama: ";
	cin >> jumlah;
	cin.ignore();
	
	string nama[jumlah];
	for(int i=0; i<jumlah; i++) {
		cout << "Nama ke-" << i+1 << ": ";
		getline(cin, nama[i]);
	}
	cout << endl;
	
	cout << "Sebelum diurutkan:" << endl;
	for(int i=0; i<jumlah; i++) {
		cout << nama[i] << ", ";
	}
	cout << endl;
	
	for(int i=1; i<jumlah; i++) {
		string key = nama[i];
		int j = i - 1;
		
		while (j >= 0 && nama[j] > key) {
			nama[j + 1] = nama[j];
			j--;
		}

		nama[j + 1] = key;
		cout << endl;
	}
	
	cout << "Setelah diurutkan berdasarkan panjang karakter" << endl;
	for (int m = 0; m < jumlah; m++) {
		cout << nama[m] << ", ";
	}
	
	return 0;
}
