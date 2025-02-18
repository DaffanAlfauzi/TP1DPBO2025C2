<?php
session_start(); // Memulai session untuk menyimpan data produk

include 'PetShop.php'; // Mengimpor kelas PetShop

$petShop = new PetShop(); // Membuat objek PetShop

// Menambahkan produk baru jika ada data yang dikirim melalui form
if (isset($_POST['add'])) {
    $name = $_POST['name'];
    $category = $_POST['category'];
    $price = $_POST['price'];
    $image = $_FILES['image']['name'];
    move_uploaded_file($_FILES['image']['tmp_name'], 'images/' . $image); // Menyimpan gambar ke folder images
    $petShop->addProduct($name, $category, $price, $image);
}

// Menghapus produk jika ada aksi delete
if (isset($_GET['action']) && $_GET['action'] == 'delete' && isset($_GET['id'])) {
    $petShop->deleteProduct($_GET['id']);
}

// Mengupdate produk jika ada aksi edit
if (isset($_GET['action']) && $_GET['action'] == 'edit' && isset($_GET['id'])) {
    $productId = $_GET['id'];
    if (isset($_POST['update'])) {
        $name = $_POST['name'];
        $category = $_POST['category'];
        $price = $_POST['price'];
        $image = $_FILES['image']['name'];
        move_uploaded_file($_FILES['image']['tmp_name'], 'images/' . $image);
        $petShop->updateProduct($productId, $name, $category, $price, $image);
    }
}

// Mencari produk jika ada input pencarian
if (isset($_GET['search'])) {
    $petShop->searchProduct($_GET['search']);
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PetShop</title>
</head>
<body>

<h1>Welcome to PetShop</h1>

<!-- Form untuk menambahkan produk -->
<form action="" method="post" enctype="multipart/form-data">
    <label for="name">Product Name:</label><br>
    <input type="text" id="name" name="name" required><br><br>

    <label for="category">Category:</label><br>
    <input type="text" id="category" name="category" required><br><br>

    <label for="price">Price:</label><br>
    <input type="number" id="price" name="price" required><br><br>

    <label for="image">Image:</label><br>
    <input type="file" id="image" name="image" required><br><br>

    <input type="submit" name="add" value="Add Product">
</form>

<hr>

<!-- Form untuk pencarian produk -->
<form action="" method="get">
    <label for="search">Search Product:</label><br>
    <input type="text" id="search" name="search" required>
    <input type="submit" value="Search">
</form>

<hr>

<h2>Product List</h2>

<?php
// Menampilkan produk
$petShop->displayProducts();
?>

<?php
// Menampilkan form edit jika produk ingin diubah
if (isset($_GET['action']) && $_GET['action'] == 'edit' && isset($_GET['id'])) {
    $productId = $_GET['id'];
    $product = null;
    foreach ($_SESSION['products'] as $p) {
        if ($p['id'] == $productId) {
            $product = $p;
            break;
        }
    }
    if ($product) {
        echo "
        <h2>Edit Product</h2>
        <form action='' method='post' enctype='multipart/form-data'>
            <label for='name'>Product Name:</label><br>
            <input type='text' id='name' name='name' value='{$product['name']}' required><br><br>
    
            <label for='category'>Category:</label><br>
            <input type='text' id='category' name='category' value='{$product['category']}' required><br><br>
    
            <label for='price'>Price:</label><br>
            <input type='number' id='price' name='price' value='{$product['price']}' required><br><br>
    
            <label for='image'>Image:</label><br>
            <input type='file' id='image' name='image'><br><br>
    
            <input type='submit' name='update' value='Update Product'>
        </form>
        ";
    }
}
?>

</body>
</html>
