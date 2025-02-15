/*
====================================================
                  DOKUMENTASI OUTPUT
                 PETSHOP MANAGEMENT SYSTEM
====================================================

Nama Program  : PetShop Management System
Bahasa        : C++
Deskripsi     : Program ini digunakan untuk mengelola daftar peralatan 
                yang tersedia di PetShop menggunakan konsep OOP. 
                Program menyediakan fitur untuk menambah, melihat, 
                mengubah, menghapus, dan mencari produk berdasarkan nama.

====================================================
1. MENAMPILKAN DAFTAR PRODUK YANG TERSEDIA
====================================================
Ketika belum ada produk dalam daftar, sistem menampilkan:

    --------------------------------------
    | ID | Nama Produk | Kategori | Harga |
    --------------------------------------
    Tidak ada produk dalam daftar.

====================================================
2. MENAMBAH PRODUK BARU
====================================================
Pengguna memilih opsi "Tambah Produk" dan memasukkan data berikut:

    Masukkan ID produk: 1
    Masukkan nama produk: Makanan Kucing
    Masukkan kategori produk: Makanan
    Masukkan harga produk: 50000

Setelah penambahan, sistem menampilkan daftar produk:

    ----------------------------------------------
    | ID | Nama Produk     | Kategori | Harga   |
    ----------------------------------------------
    | 1  | Makanan Kucing | Makanan  | 50000   |

====================================================
3. MENGUBAH PRODUK YANG SUDAH ADA
====================================================
Pengguna memilih opsi "Ubah Produk" dan memasukkan ID produk:

    Masukkan ID produk yang ingin diubah: 1

Pengguna kemudian memasukkan data baru:

    Masukkan nama baru: Makanan Anjing
    Masukkan kategori baru: Makanan
    Masukkan harga baru: 60000

Setelah perubahan, sistem menampilkan daftar terbaru:

    ----------------------------------------------
    | ID | Nama Produk     | Kategori | Harga   |
    ----------------------------------------------
    | 1  | Makanan Anjing | Makanan  | 60000   |

====================================================
4. MENGHAPUS PRODUK
====================================================
Pengguna memilih opsi "Hapus Produk" dan memasukkan ID produk:

    Masukkan ID produk yang ingin dihapus: 1

Sistem menampilkan pesan:

    Produk dengan ID 1 berhasil dihapus.

Setelah penghapusan, daftar produk kembali kosong:

    --------------------------------------
    | ID | Nama Produk | Kategori | Harga |
    --------------------------------------
    Tidak ada produk dalam daftar.

====================================================
5. MENCARI PRODUK BERDASARKAN NAMA
====================================================
Pengguna memilih opsi "Cari Produk" dan memasukkan nama produk:

    Masukkan nama produk yang ingin dicari: Makanan Anjing

Jika produk ditemukan, sistem menampilkan:

    ----------------------------------------------
    | ID | Nama Produk     | Kategori | Harga   |
    ----------------------------------------------
    | 1  | Makanan Anjing | Makanan  | 60000   |

Jika produk tidak ditemukan, sistem menampilkan:

    Produk dengan nama "Makanan Anjing" tidak ditemukan.

====================================================
                    SELESAI
====================================================
*/
