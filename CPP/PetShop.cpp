#include "PetShop.h"

// Constructor
PetShop::PetShop() : nextID(1) {}

// Menambahkan produk baru
void PetShop::addProduct(string name, string category, double price) {
    products.push_back({nextID++, name, category, price});
    cout << "Produk berhasil ditambahkan.\n";
}

// Menampilkan semua produk dalam bentuk tabel
void PetShop::displayProducts() {
    if (products.empty()) {
        cout << "Tidak ada produk tersedia.\n";
        return;
    }

    cout << "\n==============================================\n";
    cout << "| ID  | Nama Produk      | Kategori   | Harga   |\n";
    cout << "==============================================\n";

    for (const auto& p : products) {
        cout << "| " << setw(3) << p.id 
             << " | " << setw(15) << left << p.name 
             << " | " << setw(10) << left << p.category
             << " | Rp " << fixed << setprecision(2) << p.price << " |\n";
    }

    cout << "==============================================\n";
}

// Mengupdate produk berdasarkan ID
void PetShop::updateProduct(int id, string newName, string newCategory, double newPrice) {
    for (auto& p : products) {
        if (p.id == id) {
            p.name = newName;
            p.category = newCategory;
            p.price = newPrice;
            cout << "Produk berhasil diperbarui.\n";
            return;
        }
    }
    cout << "Produk dengan ID " << id << " tidak ditemukan.\n";
}

// Menghapus produk berdasarkan ID
void PetShop::deleteProduct(int id) {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].id == id) {
            products.erase(products.begin() + i);
            cout << "Produk berhasil dihapus.\n";
            return;
        }
    }
    cout << "Produk dengan ID " << id << " tidak ditemukan.\n";
}

// Mencari produk berdasarkan nama
void PetShop::searchProduct(string name) {
    bool found = false;
    cout << "\nHasil Pencarian untuk \"" << name << "\":\n";
    cout << "==============================================\n";
    cout << "| ID  | Nama Produk      | Kategori   | Harga   |\n";
    cout << "==============================================\n";

    for (const auto& p : products) {
        if (p.name == name) {
            cout << "| " << setw(3) << p.id 
                 << " | " << setw(15) << left << p.name 
                 << " | " << setw(10) << left << p.category
                 << " | Rp " << fixed << setprecision(2) << p.price << " |\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Produk tidak ditemukan.\n";
    } else {
        cout << "==============================================\n";
    }
}
