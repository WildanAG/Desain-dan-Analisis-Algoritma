#include <iostream>
using namespace std;

class silsilah {
	protected :
		string orangtua = "Doni arifitranto dan Mellynda Shafira";
		string anakanak = "Ritsuki dan Natsuki";
		
	public :
	string cekSilsilah(){
		//mengubah teks statis menjadi teks yang mengekstrak nama orangtua dari variabel yang sudah ada
		return "Ayah bernama " + orangtua.substr(0, orangtua.find(" "))+
				" dan Ibu bernama " + orangtua.substr(orangtua.find(" ")+12);
	}
};

class cucu : public silsilah{
	protected :
		string cucu = "Mamank kuliner dan Medy reynaldi";
		
	public :
		string cekAnak(){
			//mengubah tek statis menjadi teks yang mengekstrak nama anakanak dari variabel yang sudah ada
			return "Anak pertama keluarga Doni adalah " + anakanak.substr(0, anakanak.find(" "))+
				" dan anak kedua dari keluarga Doni adalah " + anakanak.substr(anakanak.find(" ")+4);
		}
};
class anak : public cucu{
		public:
		string lihatSilsilahnya(){
			return "Silsilah keluarga Doni";
		}
		
		string cekCucu() {
			//mengubah teks statis menjadi teks yang mengekstrak nama cucu dari variabel yang sudah ada
			return "Cucu pertama bernama " + cucu.substr(0, cucu.find(" "))+
				" dan cucu kedua bernama " + cucu.substr(cucu.find(" ")+4);
		}
};

int main ()
{
	anak SilsilahDoni;
	
	//output hasil dari metode2 dalam kelas anak
	
	cout << SilsilahDoni.lihatSilsilahnya() << endl;
	cout << SilsilahDoni.cekSilsilah() << endl;
	cout << SilsilahDoni.cekAnak() << endl;
	cout << SilsilahDoni.cekCucu() << endl;
	
	return 0;
	
}
