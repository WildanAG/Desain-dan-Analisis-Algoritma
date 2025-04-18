#include <iostream>
#include <string>
using namespace std;

class infobuku {
	private:
		string judul;
		string penulis;
		int tahun;
		
	public:
		infobuku() {
			judul = " ";
			penulis = " ";
			tahun = 0;
		}
		
		void setjudul(string title) {
			judul = title;
		}
		
		void setpenulis(string author) {
			penulis = author;
		}
		
		void settahun(int year) {
			tahun = year;
		}
		
	void displayinfobuku() {
		cout << "Judul : " << judul << endl;
		cout << "Penulis : " << penulis << endl;
		cout << "Tahun Terbit : " << tahun << endl;
	}
};

int main () 
{
	infobuku buku1;
	infobuku buku2;
	
	buku1.setjudul("Harry Potter");
	buku1.setpenulis("Agus");
	buku1.settahun(1990);
	
	buku2.setjudul("Petualangan si Agus");
	buku2.setpenulis("Wiledan");
	buku2.settahun(2045);
	
	buku1.displayinfobuku();
	buku2.displayinfobuku();
}
