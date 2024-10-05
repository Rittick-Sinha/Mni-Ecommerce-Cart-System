#include <iostream>
#include <string>    // For using std::string
#include <iomanip>   // For using std::setprecision
#include <sstream>   // For using std::stringstream

using namespace std;

// Product class represents a product with its id, name, price, and category
class Product {
public:
    // Constructor to initialize a Product object
    Product(const string& product_id, const string& name, float price, const string& category)
        : product_id_(product_id), name_(name), price_(price), category_(category) {}

    // Method to get the product details as a string
    string toString() const {
        // Use stringstream to format the product details
        stringstream ss;
        ss << name_ << " - Price: " << fixed << setprecision(2) << price_ << " USD";
        return ss.str();  // Return the formatted string
    }

private:
    string product_id_;
    string name_;
    float price_;
    string category_;
};

int main() {
    // Create a product instance
    Product product("123", "Laptop", 999.99, "Electronics");

    // Get product details
    string details = product.toString();
    cout << details << endl;  // Print the product details

    return 0;
}
