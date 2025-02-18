// Main.java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        PetShop shop = new PetShop();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nPetShop Management");
            System.out.println("1. Display Products");
            System.out.println("2. Add Product");
            System.out.println("3. Update Product");
            System.out.println("4. Delete Product");
            System.out.println("5. Search Product");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    shop.displayProducts();
                    break;
                case 2:
                    System.out.print("Enter product name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter category: ");
                    String category = scanner.nextLine();
                    System.out.print("Enter price: ");
                    double price = scanner.nextDouble();
                    shop.addProduct(name, category, price);
                    break;
                case 3:
                    System.out.print("Enter product ID to update: ");
                    int updateId = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Enter new name: ");
                    String newName = scanner.nextLine();
                    System.out.print("Enter new category: ");
                    String newCategory = scanner.nextLine();
                    System.out.print("Enter new price: ");
                    double newPrice = scanner.nextDouble();
                    shop.updateProduct(updateId, newName, newCategory, newPrice);
                    break;
                case 4:
                    System.out.print("Enter product ID to delete: ");
                    int deleteId = scanner.nextInt();
                    shop.deleteProduct(deleteId);
                    break;
                case 5:
                    System.out.print("Enter product name to search: ");
                    String searchName = scanner.nextLine();
                    shop.searchProduct(searchName);
                    break;
                case 6:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        } while (choice != 6);

        scanner.close();
    }
}
