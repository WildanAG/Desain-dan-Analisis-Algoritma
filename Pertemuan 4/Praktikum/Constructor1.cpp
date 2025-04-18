#include <iostream>
#include <string>
using namespace std;

class pelajaran { //class name
	public: //acces specifier
		pelajaran () { //constructor
			cout << "Ini adalah mencari materi C++ tentang constructors!";
		}
};

int main ()
{
	pelajaran obj; //membuat objek dari sebuah class
	return 0;
}
