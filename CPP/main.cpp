#include "PetShop.h"

int main() {
    PetShop shop;
    int choice;
    
    do {
        cout << "\n=== PetShop Menu ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Ubah Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, category;
            double price;
            cout << "Masukkan nama produk: ";
            getline(cin, name);
            cout << "Masukkan kategori produk: ";
            getline(cin, category);
            cout << "Masukkan harga produk: ";
            cin >> price;
            shop.addProduct(name, category, price);
        }
        else if (choice == 2) {
            shop.displayProducts();
        }
        else if (choice == 3) {
            int id;
            string newName, newCategory;
            double newPrice;
            cout << "Masukkan ID produk yang ingin diubah: ";
            cin >> id;
            cin.ignore();
            cout << "Masukkan nama baru: ";
            getline(cin, newName);
            cout << "Masukkan kategori baru: ";
            getline(cin, newCategory);
            cout << "Masukkan harga baru: ";
            cin >> newPrice;
            shop.updateProduct(id, newName, newCategory, newPrice);
        }
        else if (choice == 4) {
            int id;
            cout << "Masukkan ID produk yang ingin dihapus: ";
            cin >> id;
            shop.deleteProduct(id);
        }
        else if (choice == 5) {
            string name;
            cout << "Masukkan nama produk yang dicari: ";
            cin.ignore();
            getline(cin, name);
            shop.searchProduct(name);
        }
    } while (choice != 0);

    cout << "Terima kasih telah menggunakan sistem PetShop.\n";
    return 0;
}
