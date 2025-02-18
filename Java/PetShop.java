// PetShop.java
import java.util.ArrayList;
import java.util.Scanner;

class PetShop {
    private static class Product {
        private int id;
        private String name;
        private String category;
        private double price;

        public Product(int id, String name, String category, double price) {
            this.id = id;
            this.name = name;
            this.category = category;
            this.price = price;
        }

        public int getId() { return id; }
        public String getName() { return name; }
        public String getCategory() { return category; }
        public double getPrice() { return price; }

        public void setName(String name) { this.name = name; }
        public void setCategory(String category) { this.category = category; }
        public void setPrice(double price) { this.price = price; }

        public String toString() {
            return "ID: " + id + ", Name: " + name + ", Category: " + category + ", Price: " + price;
        }
    }

    private ArrayList<Product> products = new ArrayList<>();
    private int nextId = 1;

    public void displayProducts() {
        if (products.isEmpty()) {
            System.out.println("No products available.");
        } else {
            for (Product p : products) {
                System.out.println(p);
            }
        }
    }

    public void addProduct(String name, String category, double price) {
        products.add(new Product(nextId++, name, category, price));
    }

    public void updateProduct(int id, String name, String category, double price) {
        for (Product p : products) {
            if (p.getId() == id) {
                p.setName(name);
                p.setCategory(category);
                p.setPrice(price);
                return;
            }
        }
        System.out.println("Product not found.");
    }

    public void deleteProduct(int id) {
        products.removeIf(p -> p.getId() == id);
    }

    public void searchProduct(String name) {
        for (Product p : products) {
            if (p.getName().equalsIgnoreCase(name)) {
                System.out.println(p);
                return;
            }
        }
        System.out.println("Product not found.");
    }
}
