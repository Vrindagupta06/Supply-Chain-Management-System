# supply-chain-management-system
 project on supply chain management system in c++
Here is an enhanced and more comprehensive README file for your Supply Chain Management System written in C++. This README will guide users on how to understand, compile, and run the application, as well as explain the main functionalities.

---

# Supply Chain Management System

This C++ application simulates a Supply Chain Management System, allowing users to manage products, suppliers, customers, inventory, and orders. It provides functionalities to create and manage entities and to place orders while updating inventory levels.

## Features

- **Create Products:** Add new products to the inventory.
- **Create Suppliers:** Add new suppliers with contact information.
- **Create Customers:** Add new customers with contact details.
- **Print Products:** Display a list of all products in the inventory.
- **Add Stock:** Increase the stock level of a specific product.
- **Remove Stock:** Decrease the stock level of a specific product.
- **Place Orders:** Create and manage orders, and update inventory levels accordingly.

## Classes Overview

### Product Class
Represents a product with an ID, name, description, and price.

### Supplier Class
Represents a supplier with an ID, name, and contact information.

### Customer Class
Represents a customer with an ID, name, address, and email.

### Order Class
Represents an order containing product details, quantity, total price, status, and references to customer and supplier.

### Inventory Class
Manages the inventory of products and their quantities, allowing adding, removing, and updating stock levels.

### SCManager Class
The central manager that handles adding suppliers, customers, creating products, managing stock, and placing orders.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- Basic knowledge of C++ and command-line operations

### Compilation
1. Clone the repository or download the source code files.
2. Open a terminal or command prompt.
3. Navigate to the directory containing the source code.
4. Compile the code using the following command:
    ```bash
    g++ -o supply_chain_management main.cpp
    ```

### Running the Application
1. After compilation, run the executable:
    ```bash
    ./supply_chain_management
    ```
2. Follow the on-screen instructions to interact with the Supply Chain Management System.

## Usage

Upon running the application, you will be presented with a menu to perform various operations:

```
Supply Chain Management System
1. Create Product
2. Create Supplier
3. Create Customer
4. Print Products
5. Add Stock
6. Remove Stock
7. Place Order
0. Exit
Enter your choice:
```

### Menu Options
- **Create Product:** Prompts for product details and adds the product to the inventory.
- **Create Supplier:** Prompts for supplier details and adds the supplier to the system.
- **Create Customer:** Prompts for customer details and adds the customer to the system.
- **Print Products:** Displays all products currently in the inventory along with their details.
- **Add Stock:** Prompts for product ID and quantity, and increases the stock level of the specified product.
- **Remove Stock:** Prompts for product ID and quantity, and decreases the stock level of the specified product.
- **Place Order:** Prompts for customer ID, product ID, and quantity, creates an order, and updates the inventory.

## Example Usage

1. **Create a Product:**
    - Select "1" from the menu.
    - Enter product details as prompted.
2. **Create a Supplier:**
    - Select "2" from the menu.
    - Enter supplier details as prompted.
3. **Create a Customer:**
    - Select "3" from the menu.
    - Enter customer details as prompted.
4. **Print Products:**
    - Select "4" from the menu to view all products in the inventory.
5. **Add Stock:**
    - Select "5" from the menu.
    - Enter product ID and quantity to increase stock levels.
6. **Remove Stock:**
    - Select "6" from the menu.
    - Enter product ID and quantity to decrease stock levels.
7. **Place Order:**
    - Select "7" from the menu.
    - Enter customer ID, product ID, and quantity to create an order and update inventory.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by real-world supply chain management systems.
- Developed for educational purposes to demonstrate object-oriented programming in C++.

---

This README file should help users understand how to use the Supply Chain Management System and what functionalities it offers. Feel free to customize the content to better suit your needs.
