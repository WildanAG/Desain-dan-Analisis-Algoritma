#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
	public :
		string nama;
		int NPM;
		
	public :
		void setNama (string n) {
			nama = n;
		}
		
		void setNPM (int p) {
			NPM = p;
		}
		
		string getNama() {
			return nama;
		}
			
		int getNPM() {
			return NPM;
		}
};

int main () {
	Mahasiswa mhsw;
	string namaMahasiswa;
	int npmMahasiswa;
	
	cout << "Masukan Nama Mahasiswa : ";
	getline(cin, namaMahasiswa);
	mhsw.setNama(namaMahasiswa);
	
	cout << "Masukan NPM Mahasiswa : ";
	cin >> npmMahasiswa;
	cin.ignore();
	mhsw.setNPM(npmMahasiswa);
	
	cout << "Nama Mahasiswa : " << mhsw.getNama() << endl;
	cout << "NPM Mahasiswa : " << mhsw.getNPM() << endl;
	
	return 0;
	
	
}
