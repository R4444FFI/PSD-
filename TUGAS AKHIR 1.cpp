#include <iostream>
#include <string>
using namespace std;

struct Vector {
    string* data;
    int capacity;
    int length;
};

void init(Vector &v) {
    v.capacity = 2;
    v.length = 0;
    v.data = new string[v.capacity];
}

void resize(Vector &v, int newCap) {
    string* temp = new string[newCap];
    for (int i = 0; i < v.length; i++) {
        temp[i] = v.data[i];
    }
    delete[] v.data;
    v.data = temp;
    v.capacity = newCap;
}

void addProduct(Vector &v, string item) {
    if (v.length == v.capacity) {
        resize(v, v.capacity * 2);
    }
    v.data[v.length] = item;
    v.length++;
}

void removeProduct(Vector &v, string item) {
    int index = -1;
    for (int i = 0; i < v.length; i++) {
        if (v.data[i] == item) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < v.length - 1; i++) {
            v.data[i] = v.data[i + 1];
        }
        v.length--;
        cout << "Produk \"" << item << "\" dihapus dari keranjang.\n";
    } else {
        cout << "Produk tidak ditemukan.\n";
    }
}

void showCart(Vector &v) {
    if (v.length == 0) {
        cout << "Keranjang kosong.\n";
        return;
    }
    cout << "Isi Keranjang: [ ";
    for (int i = 0; i < v.length; i++) {
        cout << v.data[i];
        if (i < v.length - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    Vector cart;
    init(cart);

    int choice;
    string item;
    bool running = true;

    while (running) {
        cout << "\n=== MENU KERANJANG BELANJA ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Hapus Produk\n";
        cout << "3. Lihat Keranjang\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan nama produk: ";
                getline(cin, item);
                addProduct(cart, item);
                cout << "Produk ditambahkan.\n";
                break;
            case 2:
                cout << "Masukkan nama produk yang akan dihapus: ";
                getline(cin, item);
                removeProduct(cart, item);
                break;
            case 3:
                showCart(cart);
                break;
            case 4:
                running = false;
                cout << "Terima kasih telah menggunakan program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}