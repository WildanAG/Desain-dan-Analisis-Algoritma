#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;

class queue {
	private:
		int rear, front, count;
		int arr[MAX];
	public:
		queue () {
			front = 0;
			count = 0;
			rear = MAX - 1;
		}
	
	void enqueue (int x) {
		if (count >= MAX) {
			cout << "Antrian Penuh." << endl;
			return;
		}
		rear = (rear + 1) % MAX;
		arr[rear] = x;
		count++;
	}
	
	void printQueue() {
    	if (isEmpty()) {
        	cout << "~Antrian kosong~" << endl;
        	return;
   	 	}

   		 cout << "Isi antrian: ";
    	for (int i = 0; i < count; i++) {
        	int index = (front + i) % MAX;
        	cout << arr[index] << " ";
    		}
   		cout << endl;
	}
	
	int dequeue() {
        if (count <= 0) {
            cout << "Antrian kosong." << endl;
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % MAX;
        count--;
        return x;
    }

    int peek() {
        if (count <= 0) {
            cout << "Antrian kosong." << endl;
            return -1;
        }
        return arr[front];
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }
};

int main () {
	queue q;
	int p, nilai;
	do {
		cout << "---------------------------------" << endl;
		cout << "\tQueue Array" << endl;
		cout << "---------------------------------" << endl;
		cout << "1. Masukan nilai antrian" << endl;
		cout << "2. Lihat status antrian " << endl;
		cout << "3. Tampilkan antrian    " << endl;
		cout << "---------------------------------" << endl;
		cout << "Pilih perintah: ";
		cin >> p;
		cout << endl;
	
		switch(p) {
			case 1:
				for(int i=0; i<MAX; i++) {
					cin >> nilai;
					q.enqueue(nilai);
				}
				cout << endl;
				break;
			case 2:
				cout << "Status:" << endl;
				if (q.isEmpty()) {
					cout << "~kosong~" << endl;
				} else if (q.isFull()) {
					cout << "~penuh~" << endl;
				}
				cout << endl;
				break;
			case 3:
				q.printQueue();
				cout << endl;
				break;
		}
	}while (p != 0);
	return 0;
}
