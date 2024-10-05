#include <iostream>   // For input/output streams
#include <cstring>    // For strcpy, strcat, strcmp
#include <cstdio>     // For sprintf

using namespace std;

// Product class representing a product
class Product {
public:
    char product_id_[20];
    char name_[50];
    float price_;

    Product(const char* id, const char* name, float price) {
        strcpy(product_id_, id);
        strcpy(name_, name);
        price_ = price;
    }

    const char* toString() const {
        return name_;
    }
};

// CartItem class representing an item in the cart
class CartItem {
public:
    Product product_;
    int quantity_;

    CartItem(Product product, int quantity) : product_(product), quantity_(quantity) {}
};

// Cart class representing a shopping cart
class Cart {
public:
    Cart() : itemCount_(0) {}

    // Method to add an item to the cart
    void addItem(Product product, int quantity) {
        int index = findProductIndex(product.product_id_);
        if (index != -1) {
            // Product already in cart, increase quantity
            items_[index].quantity_ += quantity;
        } else {
            // Add new product to cart
            items_[itemCount_] = CartItem(product, quantity);
            itemCount_++;
        }
    }

    // Method to remove an item from the cart
    void removeItem(const char* product_id, int quantity) {
        int index = findProductIndex(product_id);
        if (index != -1) {
            if (items_[index].quantity_ <= quantity) {
                // Remove the item from the cart
                for (int i = index; i < itemCount_ - 1; ++i) {
                    items_[i] = items_[i + 1];
                }
                itemCount_--;
            } else {
                // Decrease the quantity
                items_[index].quantity_ -= quantity;
            }
        }
    }

    // Method to view the cart contents
    const char* viewCart() {
        static char cartContents[1000] = "";
        cartContents[0] = '\0';  // Reset cart contents string
        float totalCost = 0;

        for (int i = 0; i < itemCount_; ++i) {
            char itemString[200];
            Product product = items_[i].product_;
            int quantity = items_[i].quantity_;
            totalCost += product.price_ * quantity;
            sprintf(itemString, "%s - Quantity: %d, Price: %.2f USD, Total: %.2f USD\n", product.toString(), quantity, product.price_, product.price_ * quantity);
            strcat(cartContents, itemString);
        }

        char totalCostString[100];
        sprintf(totalCostString, "Total (before discounts): %.2f USD", totalCost);
        strcat(cartContents, totalCostString);

        return cartContents;
    }

    // Method to apply discounts to the cart contents
    void applyDiscount(float discountPercent) {
        float totalCost = 0;

        for (int i = 0; i < itemCount_; ++i) {
            totalCost += items_[i].product_.price_ * items_[i].quantity_;
        }

        float discountAmount = totalCost * (discountPercent / 100);
        totalCost -= discountAmount;

        printf("Total after %.2f%% discount: %.2f USD\n", discountPercent, totalCost);
    }

private:
    CartItem items_[100];  // Static array to store cart items
    int itemCount_;

    // Method to find the index of a product in the cart
    int findProductIndex(const char* product_id) {
        for (int i = 0; i < itemCount_; ++i) {
            if (strcmp(items_[i].product_.product_id_, product_id) == 0) {
                return i;
            }
        }
        return -1;  // Product not found
    }
};

int main() {
    Cart cart;

    Product product1("101", "Laptop", 1000.0);
    Product product2("102", "Phone", 500.0);

    cart.addItem(product1, 1);
    cart.addItem(product2, 2);

    cout << cart.viewCart() << endl;

    cart.applyDiscount(10);  // Apply a 10% discount

    return 0;
}
