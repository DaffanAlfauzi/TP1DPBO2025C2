from petshop import PetShop

def main():
    shop = PetShop()
    
    while True:
        print("\n=== PetShop Management ===")
        print("1. Tambah Produk")
        print("2. Tampilkan Produk")
        print("3. Ubah Produk")
        print("4. Hapus Produk")
        print("5. Cari Produk")
        print("6. Keluar")
        choice = input("Pilih opsi: ")

        if choice == "1":
            product_id = input("ID: ")
            name = input("Nama Produk: ")
            category = input("Kategori: ")
            price = float(input("Harga: "))
            shop.add_product(product_id, name, category, price)

        elif choice == "2":
            shop.display_products()

        elif choice == "3":
            product_id = input("ID Produk yang akan diubah: ")
            name = input("Nama Baru: ")
            category = input("Kategori Baru: ")
            price = float(input("Harga Baru: "))
            shop.update_product(product_id, name, category, price)

        elif choice == "4":
            product_id = input("ID Produk yang akan dihapus: ")
            shop.delete_product(product_id)

        elif choice == "5":
            name = input("Masukkan nama produk yang dicari: ")
            shop.search_product(name)

        elif choice == "6":
            print("Keluar dari program.")
            break

        else:
            print("Pilihan tidak valid.")

if __name__ == "__main__":
    main()
