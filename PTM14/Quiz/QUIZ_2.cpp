#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    const int MAX_SIZE = 5;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int data) {
        if (size == MAX_SIZE) {
            cout << "Queue penuh (Overflow)." << endl;
            return;
        }

        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;

        if (rear == NULL) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }

        size++;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue kosong (Underflow)." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        cout << "Dequeue: " << temp->data << endl;
        delete temp;
        size--;
    }

    int front_element() {
        if (front == NULL) {
            cout << "Queue kosong." << endl;
            return -1;
        }
        return front->data;
    }

    bool is_empty() {
        return (front == NULL);
    }

    void tampilkan() {
        if (is_empty()) {
            cout << "Queue kosong." << endl;
            return;
        }

        cout << "Isi Queue: ";
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void menu() {
    	int p;
    	int nomor;
    	cout << "========================" << endl;
    	cout << "1. Hapuskan queue depan" << endl;
    	cout << "2. Tampilkan queue" << endl;
    	cout << "3. Tambah queue" << endl;
    	cout << "========================" << endl;
    	cin >> p;
    	if(p == 1) {
			dequeue();
		} else if(p == 2) {    		
        	tampilkan();
    	} else if(p == 3) {
    		cout << "Masukan angka";
    		cin >> nomor;
    		enqueue(nomor);
		} else {
			cout << "selesai" << endl;
		}
		menu();
	}
};

int main() {
    Queue q;
    int data;
    cout << "Masukkan 5 data untuk dimasukkan ke queue:\n";
    for (int i = 0; i < 5; i++) {
        cin >> data;
        q.enqueue(data);
    }
	q.menu(); 
       
    return 0;
}

