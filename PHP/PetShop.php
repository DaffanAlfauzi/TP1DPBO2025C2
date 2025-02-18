<?php
class PetShop {
    public function __construct() {
        // Memulai session jika belum ada
        if (!isset($_SESSION['products'])) {
            $_SESSION['products'] = [];
        }
    }

    // Menambahkan produk baru
    public function addProduct($name, $category, $price, $image) {
        $product = [
            'id' => count($_SESSION['products']) + 1, // Menghasilkan ID secara otomatis
            'name' => $name,
            'category' => $category,
            'price' => $price,
            'image' => $image
        ];
        $_SESSION['products'][] = $product;
    }

    // Menampilkan produk
    public function displayProducts() {
        if (empty($_SESSION['products'])) {
            echo "<p>No products available.</p>";
            return;
        }

        echo "<table border='1'>
                <tr>
                    <th>ID</th>
                    <th>Name</th>
                    <th>Category</th>
                    <th>Price</th>
                    <th>Image</th>
                    <th>Actions</th>
                </tr>";

        foreach ($_SESSION['products'] as $product) {
            echo "<tr>
                    <td>{$product['id']}</td>
                    <td>{$product['name']}</td>
                    <td>{$product['category']}</td>
                    <td>\${$product['price']}</td>
                    <td><img src='images/{$product['image']}' width='50'></td>
                    <td>
                        <a href='?action=edit&id={$product['id']}'>Edit</a> |
                        <a href='?action=delete&id={$product['id']}'>Delete</a>
                    </td>
                  </tr>";
        }
        echo "</table>";
    }

    // Menghapus produk berdasarkan ID
    public function deleteProduct($id) {
        foreach ($_SESSION['products'] as $key => $product) {
            if ($product['id'] == $id) {
                unset($_SESSION['products'][$key]); // Hapus produk berdasarkan ID
                $_SESSION['products'] = array_values($_SESSION['products']); // Menata ulang array
                return;
            }
        }
    }

    // Mencari produk berdasarkan nama
    public function searchProduct($name) {
        $found = false;
        foreach ($_SESSION['products'] as $product) {
            if (stripos($product['name'], $name) !== false) {
                echo "<p>Found: {$product['name']} ({$product['category']}) - \${$product['price']}</p>";
                $found = true;
            }
        }
        if (!$found) {
            echo "<p>No product found with the name '$name'.</p>";
        }
    }

    // Mengubah produk berdasarkan ID
    public function updateProduct($id, $newName, $newCategory, $newPrice, $newImage) {
        foreach ($_SESSION['products'] as &$product) {
            if ($product['id'] == $id) {
                $product['name'] = $newName;
                $product['category'] = $newCategory;
                $product['price'] = $newPrice;
                $product['image'] = $newImage;
                return;
            }
        }
    }
}
?>
