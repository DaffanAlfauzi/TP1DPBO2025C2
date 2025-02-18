class PetShop:
    def __init__(self):
        self.products = {}  # Dictionary untuk menyimpan produk

    def add_product(self, product_id, name, category, price):
        if product_id in self.products:
            print("ID sudah digunakan!")
            return
        self.products[product_id] = {
            "name": name,
            "category": category,
            "price": price
        }
        print(f"Produk '{name}' berhasil ditambahkan!")

    def display_products(self):
        if not self.products:
            print("Tidak ada produk.")
            return
        print("\nDaftar Produk:")
        print("{:<5} {:<15} {:<10} {:<10}".format("ID", "Nama", "Kategori", "Harga"))
        for product_id, details in self.products.items():
            print(f"{product_id:<5} {details['name']:<15} {details['category']:<10} {details['price']:<10}")

    def update_product(self, product_id, name, category, price):
        if product_id not in self.products:
            print("Produk tidak ditemukan!")
            return
        self.products[product_id] = {"name": name, "category": category, "price": price}
        print(f"Produk '{name}' berhasil diperbarui!")

    def delete_product(self, product_id):
        if product_id not in self.products:
            print("Produk tidak ditemukan!")
            return
        del self.products[product_id]
        print("Produk berhasil dihapus!")

    def search_product(self, name):
        found = False
        for product_id, details in self.products.items():
            if details["name"].lower() == name.lower():
                print(f"Produk ditemukan: ID {product_id}, {details}")
                found = True
        if not found:
            print("Produk tidak ditemukan.")
