#include <iostream>     // for input/output operations
#include <stdexcept>    // for exception handling
#include <cstring>      // for strcmp
#include <string>       // for std::string

using namespace std;

// Forward declaration of the Product class
class Product {
public:
    float price_;
    Product(float price) : price_(price) {}
};

// Discount class represents a discount with its name, category, type, and value
class Discount {
public:
    // Constructor to initialize a Discount object
    Discount(const char* name, const char* category, const char* discount_type, float discount_value) 
        : name_(name), category_(category), discount_type_(discount_type), discount_value_(discount_value) {}

    // Method to apply the discount to a product
    float applyDiscount(const Product& product, int quantity) {
        // Check the discount type and apply the discount accordingly
        if (strcmp(discount_type_, "percentage") == 0) {
            // Calculate the discount amount for percentage discount
            return product.price_ * quantity * (1 - discount_value_ / 100);
        } else if (strcmp(discount_type_, "buy_one_get_one_free") == 0) {
            // Calculate the discount amount for buy one get one free discount
            return product.price_ * (quantity / 2 + quantity % 2);
        } else {
            // Throw an error for invalid discount type
            throw invalid_argument("Invalid discount type");
        }
    }

    // Method to get the discount details as a string
    string toString() {
        // Create a string to store the discount details
        string discountDetails = string(name_) + " on " + category_ + " items";
        return discountDetails;
    }

private:
    const char* name_;
    const char* category_;
    const char* discount_type_;
    float discount_value_;
};

int main() {
    // Example usage
    Product product(100.0f);  // Product with price $100
    Discount discount("Summer Sale", "Electronics", "percentage", 10.0f);  // 10% off discount
    int quantity = 5;
    
    try {
        // Apply the discount and print the final price
        float finalPrice = discount.applyDiscount(product, quantity);
        cout << "Final Price: " << finalPrice << endl;

        // Print discount details
        cout << "Discount Details: " << discount.toString() << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
