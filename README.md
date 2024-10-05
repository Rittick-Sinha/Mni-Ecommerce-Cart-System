# Mini E-commerce Cart System

## Overview
This is a command-line based Mini E-commerce Cart System where users can:
- Add items to a cart.
- Remove items from the cart.
- View current items in the cart.
- Calculate the total price in multiple currencies.
- Apply discounts dynamically (Buy 1 Get 1 Free, 10% Off).
- Checkout to see the final price with applied discounts.

This system is implemented using C++ and follows Object-Oriented Programming (OOP) principles for modularity and scalability.

## Features
1. **Product Management**: 
   - Each product has a unique ID, name, price (in USD), and category (e.g., Electronics, Fashion).
   - A predefined product catalog is available with multiple products.
   
2. **Cart Operations**:
   - Users can add multiple items to the cart with quantities.
   - Users can remove items or reduce quantities from the cart.
   - The system shows a detailed view of the cart, including total cost before discounts.

3. **Discount System**:
   - Discounts are applied dynamically based on cart contents.
   - Discounts:
     - Buy 1 Get 1 Free for Fashion items.
     - 10% Off for Electronics items.
   - Discounts are modular and can be extended easily.

4. **Currency Conversion**:
   - The total price can be converted from USD to EUR and GBP.
   - Fixed exchange rates: 
     - USD to EUR = 0.85
     - USD to GBP = 0.75

5. **Checkout**:
   - Discounts are applied automatically at checkout.
   - The final price is shown, with the option to view the price in different currencies.

## System Requirements
- C++ compiler (e.g., GCC, Clang)
- Compatible with Linux, macOS, or Windows command-line interface (CLI).

## Getting Started

### 1. Compilation
To compile the system, use a C++ compiler such as `g++`. Run the following command:

g++ -o ecommerce_cart_system main.cpp
This will create an executable file named ecommerce_cart_system.


### 2. Running the System
After compilation, run the system using the following command:
./ecommerce_cart_system

The system will start and display a menu of available options, such as adding products, viewing the cart, applying discounts, and checking out. Here's an example of how the system might look:

Welcome to the E-commerce Cart System!
Please select an option:
1. Add product to cart
2. Remove product from cart
3. View cart
4. Apply discount
5. Checkout
6. Exit

Use the numbers associated with each option to interact with the system.

### 3. Commands and Examples
**1. Add Items to the Cart**
> add_to_cart <Product_ID> <Quantity>

Adds the specified product and quantity to the cart. For example:
> add_to_cart 101 1  # Adds 1 Laptop to the cart.
> add_to_cart 102 2  # Adds 2 Phones to the cart.

**2. Remove Items from the Cart**
> remove_from_cart <Product_ID> <Quantity>

Removes the specified quantity of the product from the cart or removes the entire item if the quantity reaches zero

**3. View Cart**
> view_cart

Displays the cart contents and total cost before discounts. Example output:
Your Cart:
1. Laptop - Quantity: 1, Price: 1000.00 USD, Total: 1000.00 USD
2. Phone - Quantity: 2, Price: 500.00 USD, Total: 1000.00 USD
Total (before discounts): 2000.00 USD

**4. List Available Discounts**
> list_discounts

Displays all currently available discounts:
Available Discounts:
1. Buy 1 Get 1 Free on Fashion items.
2. 10% Off on Electronics.

**5. Checkout**
> checkout

Applies all available discounts and displays the final price. Example:
Applying discounts...
10% Off on Electronics applied.
Final Total in USD: 1900.00

**6. Currency Conversion at Checkout**
After checkout, the system asks if you would like to view the final total in another currency:
Would you like to view it in a different currency? (yes/no): yes
Available Currencies: EUR, GBP
Enter currency: EUR
Final Total in EUR: 1615.00



## System Architecture
### 1. Classes
**1.1 Product**
Represents a product in the system, with the following attributes:

product_id_: Unique identifier (string).
name_: Product name (string).
price_: Product price in USD (float).
category_: Product category (string).
Example methods:

toString(): Returns a string representation of the product.

**1.2 CartItem**
Represents an item in the cart, with the following attributes:

Product: The product added to the cart.
quantity_: The number of units of the product.

**1.3 Cart**
Manages the collection of CartItem objects and supports the following operations:

addItem(): Adds a product to the cart.
removeItem(): Removes a product or decreases its quantity.
viewCart(): Displays the current cart contents and total cost.
applyDiscount(): Applies discounts to the total price.

**1.4 Discount**
Represents a discount rule in the system. Each discount has:

name_: Name of the discount (e.g., "10% Off on Electronics").
category_: The product category to which the discount applies (e.g., Electronics).
discount_type_: The type of discount, such as percentage or buy-one-get-one-free.
discount_value_: The value of the discount (e.g., 10 for 10%).
Example methods:

applyDiscount(): Applies the discount to the product price.
toString(): Returns a string representation of the discount details.

### 2. Extensibility
The system is designed to be easily extensible. New product categories and discount types can be added with minimal changes to the existing codebase. Discounts are applied automatically based on the contents of the cart, making the system flexible for future expansions.

**This code is written by Rittick Sinha(121CR0964), NIT Rourkela Student**