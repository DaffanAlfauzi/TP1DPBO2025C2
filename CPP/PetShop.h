#ifndef PETSHOP_H
#define PETSHOP_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class PetShop {
private:
    struct Product {
        int id;
        string name;
        string category;
        double price;
    };

    vector<Product> products;
    int nextID;

public:
    PetShop();
    
    void addProduct(string name, string category, double price);
    void displayProducts();
    void updateProduct(int id, string newName, string newCategory, double newPrice);
    void deleteProduct(int id);
    void searchProduct(string name);
};

#endif
