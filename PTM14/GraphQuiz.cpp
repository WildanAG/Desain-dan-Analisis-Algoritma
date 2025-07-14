#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
#include <iomanip>
#include <set>
using namespace std;

map<string, vector<pair<string, int> > > adj;
map<string, int> jarak;
map<string, string> prev;
map<string, map<string, int> > dist_fw;
set<string> semua_siswa;

void dijkstra(string sumber) {
    map<string, vector<pair<string, int> > >::iterator it;
    for (it = adj.begin(); it != adj.end(); ++it) {
        jarak[it->first] = INT_MAX;
    }
    jarak[sumber] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
    pq.push(make_pair(0, sumber));

    while (!pq.empty()) {
        pair<int, string> top = pq.top();
        int jaraksekarang = top.first;
        string sekarang = top.second;
        pq.pop();

        vector<pair<string, int> >::iterator tetangga_it;
        for (tetangga_it = adj[sekarang].begin(); tetangga_it != adj[sekarang].end(); ++tetangga_it) {
            string tetangga = tetangga_it->first;
            int bobot = tetangga_it->second;

            int jarakbaru = jarak[sekarang] + bobot;
            if (jarakbaru < jarak[tetangga]) {
                jarak[tetangga] = jarakbaru;
                prev[tetangga] = sekarang;
                pq.push(make_pair(jarakbaru, tetangga));
            }
        }
    }
}

void cetakJalur(string tujuan, string sumber) {
    stack<string> path;
    string current = tujuan;

    while (current != sumber && prev.count(current)) {
        path.push(current);
        current = prev[current];
    }

    if (current != sumber) {
        cout << "Tidak ada jalur dari " << sumber << " ke " << tujuan << endl;
        return;
    }

    cout << "Jalur: " << sumber;
    while (!path.empty()) {
        cout << " --> " << path.top();
        path.pop();
    }
    cout << endl;
}

void inisialisasiFloydWarshall() {
    set<string>::iterator it1, it2;

    // Inisialisasi jarak awal
    for (it1 = semua_siswa.begin(); it1 != semua_siswa.end(); ++it1) {
        for (it2 = semua_siswa.begin(); it2 != semua_siswa.end(); ++it2) {
            if (*it1 == *it2) {
                dist_fw[*it1][*it2] = 0;
            } else {
                dist_fw[*it1][*it2] = INT_MAX;
            }
        }
    }

    // Masukkan data dari graf
    map<string, vector<pair<string, int> > >::iterator i;
    for (i = adj.begin(); i != adj.end(); ++i) {
        string dari = i->first;
        vector<pair<string, int> >::iterator j;
        for (j = i->second.begin(); j != i->second.end(); ++j) {
            string ke = j->first;
            int bobot = j->second;
            dist_fw[dari][ke] = bobot;
        }
    }

    // Algoritma Floyd-Warshall
    for (it1 = semua_siswa.begin(); it1 != semua_siswa.end(); ++it1) {
        string k = *it1;
        for (it2 = semua_siswa.begin(); it2 != semua_siswa.end(); ++it2) {
            string i = *it2;
            set<string>::iterator it3;
            for (it3 = semua_siswa.begin(); it3 != semua_siswa.end(); ++it3) {
                string j = *it3;

                if (dist_fw[i][k] != INT_MAX && dist_fw[k][j] != INT_MAX) {
                    if (dist_fw[i][j] > dist_fw[i][k] + dist_fw[k][j]) {
                        dist_fw[i][j] = dist_fw[i][k] + dist_fw[k][j];
                    }
                }
            }
        }
    }
}

void cetakMatriksFloydWarshall() {
    cout << "\nMatriks Jarak Terpendek (Floyd-Warshall)\n" << endl;

    cout << setw(12) << " ";
    set<string>::iterator it;
    for (it = semua_siswa.begin(); it != semua_siswa.end(); ++it) {
        cout << setw(10) << *it;
    }
    cout << endl;

    set<string>::iterator i, j;
    for (i = semua_siswa.begin(); i != semua_siswa.end(); ++i) {
        cout << setw(12) << *i;
        for (j = semua_siswa.begin(); j != semua_siswa.end(); ++j) {
            if (dist_fw[*i][*j] == INT_MAX)
                cout << setw(10) << "-";
            else
                cout << setw(10) << dist_fw[*i][*j];
        }
        cout << endl;
    }
}

int main() {
    string tujuan;
    
    // Data graf (biar rapi, simpan di array juga bisa)
	adj["Kyanka"].push_back({"Dava", 1});
	adj["Kyanka"].push_back({"Abrar", 3});
	adj["Dava"].push_back({"Kyanka", 1});
	adj["Dava"].push_back({"Doni", 1});
	adj["Dava"].push_back({"Azizah", 2});
	adj["Abrar"].push_back({"Kyanka", 3});
	adj["Abrar"].push_back({"Azizah", 1});
	adj["Abrar"].push_back({"Steven", 2});
	adj["Steven"].push_back({"Abrar", 2});
	adj["Steven"].push_back({"Azizah", 1});
	adj["Azizah"].push_back({"Abrar", 1});
	adj["Azizah"].push_back({"Steven", 1});
	adj["Azizah"].push_back({"Dava", 2});
	adj["Azizah"].push_back({"Annisa", 2});
	adj["Doni"].push_back({"Dava", 1});
	adj["Doni"].push_back({"Wildan", 2});
	adj["Doni"].push_back({"Annisa", 4});
	adj["Annisa"].push_back({"Azizah", 2});
	adj["Annisa"].push_back({"Doni", 4});
	adj["Annisa"].push_back({"Jonathan", 1});
	adj["Annisa"].push_back({"Yunita", 2});
	adj["Wildan"].push_back({"Doni", 2});
	adj["Wildan"].push_back({"Haikal", 4});
	adj["Wildan"].push_back({"Jonathan", 1});
	adj["Haikal"].push_back({"Wildan", 4});
	adj["Haikal"].push_back({"Agus", 4});
	adj["Agus"].push_back({"Haikal", 4});
	adj["Agus"].push_back({"Rofii", 2});
	adj["Jonathan"].push_back({"Annisa", 1});
	adj["Jonathan"].push_back({"Wildan", 1});
	adj["Jonathan"].push_back({"Rofii", 2});
	adj["Rofii"].push_back({"Jonathan", 2});
	adj["Rofii"].push_back({"Agus", 2});
	adj["Rofii"].push_back({"Ale", 2});
	adj["Yunita"].push_back({"Annisa", 2});
	adj["Yunita"].push_back({"Martin", 1});
	adj["Martin"].push_back({"Yunita", 1});
	adj["Martin"].push_back({"Sudrajat", 3});
	adj["Martin"].push_back({"Nanda", 1});
	adj["Sudrajat"].push_back({"Martin", 3});
	adj["Sudrajat"].push_back({"Nanda", 4});
	adj["Nanda"].push_back({"Jonathan", 2});
	adj["Nanda"].push_back({"Sudrajat", 4});
	adj["Nanda"].push_back({"Martin", 1});
	adj["Nanda"].push_back({"Ale", 2});
	adj["Ale"].push_back({"Nanda", 2});
	adj["Ale"].push_back({"Rofii", 2});
	adj["Ale"].push_back({"Agung", 1});
	adj["Agung"].push_back({"Ale", 1});

    // Masukkan semua node ke dalam set
    map<string, vector<pair<string, int> > >::iterator it;
    for (it = adj.begin(); it != adj.end(); ++it) {
        semua_siswa.insert(it->first);
        vector<pair<string, int> >::iterator jt;
        for (jt = it->second.begin(); jt != it->second.end(); ++jt) {
            semua_siswa.insert(jt->first);
        }
    }

    string sumber;
    cout << "Masukan asal: ";
    cin >> sumber;
    cout << "Node asal     : " << sumber << endl;
    cout << "Masukan tujuan: ";
    cin >> tujuan;

    dijkstra(sumber);

    int jrk = jarak[tujuan];
    if (jrk == INT_MAX) {
        cout << "Tidak ada jalur dari " << sumber << " ke " << tujuan << endl;
    } else {
        cout << sumber << " --> " << tujuan << " = " << jrk << " satuan waktu" << endl;
        cetakJalur(tujuan, sumber);
    }
	
	char q;
	cout << "Ingin cetak matriks? (Y/N): ";
	cin >> q;
	if(q == 'y' || q == 'Y') {
		inisialisasiFloydWarshall();
    	cetakMatriksFloydWarshall();	
	} else {
		cout << "selesai" << endl;
	}
    

    return 0;
}

