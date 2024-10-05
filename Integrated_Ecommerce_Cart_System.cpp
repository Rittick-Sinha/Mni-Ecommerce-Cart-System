#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

// Product class
class Product {
public:
    string product_id_;
    string name_;
    float price_;
    string category_;

    Product(string id, string name, float price, string category)
        : product_id_(id), name_(name), price_(price), category_(category) {}

    const string& toString() const {
        return name_;
    }
};

// CartItem class
class CartItem {
public:
    Product product_;
    int quantity_;

    CartItem(Product product, int quantity) : product_(product), quantity_(quantity) {}
};

// Cart class
class Cart {
public:
    Cart() {}

    // Add item to cart
    void addItem(Product product, int quantity) {
        int index = findProductIndex(product.product_id_);
        if (index != -1) {
            items_[index].quantity_ += quantity;
        } else {
            items_.emplace_back(product, quantity);
        }
    }

    // Remove item from cart
    void removeItem(const string& product_id, int quantity) {
        int index = findProductIndex(product_id);
        if (index != -1) {
            if (items_[index].quantity_ <= quantity) {
                items_.erase(items_.begin() + index);
            } else {
                items_[index].quantity_ -= quantity;
            }
        }
    }

    // View cart
    string viewCart() {
        stringstream cartContents;
        float totalCost = 0;

        for (const auto& item : items_) {
            cartContents << item.product_.toString() << " - Quantity: " << item.quantity_
                         << ", Price: " << fixed << setprecision(2) << item.product_.price_
                         << " USD, Total: " << item.product_.price_ * item.quantity_ << " USD\n";
            totalCost += item.product_.price_ * item.quantity_;
        }

        cartContents << "Total (before discounts): " << fixed << setprecision(2) << totalCost << " USD";
        return cartContents.str();
    }

    // Apply discounts to the cart contents
    float applyDiscounts() {
        float totalCost = 0;
        for (const auto& item : items_) {
            totalCost += item.product_.price_ * item.quantity_;
        }
        return totalCost;
    }

    // Method to get all cart items for discount processing
    const vector<CartItem>& getItems() const {
        return items_;
    }

private:
    vector<CartItem> items_;

    // Find product index in the cart
    int findProductIndex(const string& product_id) const {
        for (int i = 0; i < items_.size(); ++i) {
            if (items_[i].product_.product_id_ == product_id) {
                return i;
            }
        }
        return -1;
    }
};

// Discount class
class Discount {
public:
    Discount(const string& name, const string& category, const string& discount_type, float discount_value)
        : name_(name), category_(category), discount_type_(discount_type), discount_value_(discount_value) {}

    // Apply the discount based on type
    float applyDiscount(const CartItem& item) {
        if (item.product_.category_ == category_) {
            if (discount_type_ == "percentage") {
                return item.product_.price_ * item.quantity_ * (1 - discount_value_ / 100);
            } else if (discount_type_ == "buy_one_get_one_free") {
                int discountedQuantity = item.quantity_ / 2 + item.quantity_ % 2;
                return item.product_.price_ * discountedQuantity;
            }
        }
        return item.product_.price_ * item.quantity_;
    }

    string toString() const {
        return name_ + " on " + category_ + " items";
    }

private:
    string name_;
    string category_;
    string discount_type_;
    float discount_value_;
};

// Currency Converter class
class CurrencyConverter {
public:
    static float convertTo(const string& currency, float amount) {
        if (currency == "EUR") {
            return amount * 0.85;
        } else if (currency == "GBP") {
            return amount * 0.75;
        } else {
            return amount;
        }
    }
};

// Predefined product catalog
vector<Product> productCatalog = {
    Product("P001", "Laptop", 1000.0, "Electronics"),
    Product("P002", "Phone", 500.0, "Electronics"),
    Product("P003", "T-Shirt", 20.0, "Fashion")
};

// Predefined discounts
vector<Discount> availableDiscounts = {
    Discount("10% Off", "Electronics", "percentage", 10.0),
    Discount("Buy 1 Get 1 Free", "Fashion", "buy_one_get_one_free", 0)
};

// Display available discounts
void listDiscounts() {
    cout << "Available Discounts:\n";
    for (const auto& discount : availableDiscounts) {
        cout << discount.toString() << endl;
    }
}

// Main function
int main() {
    Cart cart;

    // Simulate user adding products to cart
    cart.addItem(productCatalog[0], 1); // Add 1 Laptop
    cart.addItem(productCatalog[2], 2); // Add 2 T-Shirts

    // View cart before discounts
    cout << cart.viewCart() << endl;

    // Apply discounts
    float totalAfterDiscounts = 0;
    for (const auto& item : cart.getItems()) {
        for (const auto& discount : availableDiscounts) {
            totalAfterDiscounts += discount.applyDiscount(item);
        }
    }
    cout << "\nTotal after discounts: " << fixed << setprecision(2) << totalAfterDiscounts << " USD\n";

    // Currency conversion
    string currency;
    cout << "Would you like to convert to a different currency? (yes/no): ";
    cin >> currency;
    if (currency == "yes") {
        cout << "Available currencies: EUR, GBP\nEnter currency: ";
        cin >> currency;
        float convertedAmount = CurrencyConverter::convertTo(currency, totalAfterDiscounts);
        cout << "Final Total in " << currency << ": " << fixed << setprecision(2) << convertedAmount << endl;
    }

    return 0;
}
