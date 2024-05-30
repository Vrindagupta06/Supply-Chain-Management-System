#include <iostream>
#include <string>

using namespace std;

class Product;
class Order;
class Inventory;
class Customer;

// Product class
class Product {
public:
    static int lastId;
    int id;
    string name;
    string description;
    double price;

    Product() : id(0), name(""), description(""), price(0.0) {}

    Product(string name, string description, double price)
        : id(++lastId), name(name), description(description), price(price) {}

    void updatePrice(double newPrice) {
        price = newPrice;
    }
};

int Product::lastId = 0;

// Supplier class
class Supplier {
public:
    int id;
    string name;
    string contactInfo;

    Supplier() : id(0), name(""), contactInfo("") {}

    Supplier(int id, string name, string contactInfo)
        : id(id), name(name), contactInfo(contactInfo) {}

    void updateContactInfo(const string& newContactInfo) {
        contactInfo = newContactInfo;
    }
};

// Order class
class Order {
public:
    int id;
    Product* products;
    int quantity;
    double totalPrice;
    string status;
    Customer* customer;
    Supplier* supplier;

    Order(int id, Customer* customer, Supplier* supplier)
        : id(id), customer(customer), supplier(supplier) {}

    void updateStatus(const string& newStatus) {
        status = newStatus;
    }
};

// Inventory class
class Inventory {
public:
    int id;
    Product* products;
    int* quantities;
    int size;

    Inventory(int id, int size) : id(id), size(size) {
        products = new Product[size];
        quantities = new int[size];
    }

    ~Inventory() {
        delete[] products;
        delete[] quantities;
    }

    void addProduct(Product product, int quantity) {
        for (int i = 0; i < size; ++i) {
            if (products[i].id == 0) {
                products[i] = product;
                quantities[i] = quantity;
                return;
            }
        }
    }

    void removeProduct(int productId) {
        for (int i = 0; i < size; ++i) {
            if (products[i].id == productId) {
                products[i] = Product();
                quantities[i] = 0;
                return;
            }
        }
    }

    void updateQuantity(int productId, int quantity) {
        for (int i = 0; i < size; ++i) {
            if (products[i].id == productId) {
                quantities[i] = quantity;
                return;
            }
        }
    }

    void addStock(int productId, int quantity) {
        for (int i = 0; i < size; ++i) {
            if (products[i].id == productId) {
                quantities[i] += quantity;
                return;
            }
        }
    }

    void removeStock(int productId, int quantity) {
        for (int i = 0; i < size; ++i) {
            if (products[i].id == productId) {
                if (quantities[i] >= quantity) {
                    quantities[i] -= quantity;
                    return;
                } else {
                    cout << "Error: Not enough stock available!" << endl;
                    return;
                }
            }
        }
        cout << "Error: Product not found in inventory!" << endl;
    }
};

// Customer class
class Customer {
public:
    int id;
    string name;
    string address;
    string email;

    Customer() : id(0), name(""), address(""), email("") {}

    Customer(int id, string name, string address, string email)
        : id(id), name(name), address(address), email(email) {}

    void updateAddress(const string& newAddress) {
        address = newAddress;
    }
};

// SCManager class
class SCManager {
private:
    Supplier* suppliers;
    Inventory inventory;
    Customer* customers;
    int supplierCount;
    int customerCount;

public:
    SCManager(int inventorySize, int maxSuppliers, int maxCustomers) : inventory(0, inventorySize), supplierCount(0), customerCount(0) {
        suppliers = new Supplier[maxSuppliers];
        customers = new Customer[maxCustomers];
    }

    ~SCManager() {
        delete[] suppliers;
        delete[] customers;
    }

    void addSupplier(Supplier supplier) {
        suppliers[supplierCount++] = supplier;
    }

    void addCustomer(Customer customer) {
        customers[customerCount++] = customer;
    }

    void createProduct() {
        string name, description;
        double price;

        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Product Description: ";
        getline(cin, description);

        cout << "Enter Product Price: ";
        cin >> price;

        Product newProduct(name, description, price);
        inventory.addProduct(newProduct, 0);
    }

    void printProducts() {
        cout << "Inventory Products: " << endl;
        for (int i = 0; i < inventory.size; ++i) {
            if (inventory.products[i].id != 0) {
                cout << "ID: " << inventory.products[i].id << ", Name: " << inventory.products[i].name << ", Price: $" << inventory.products[i].price << ", Quantity: " << inventory.quantities[i] << endl;
            }
        }
    }

    void createSupplier() {
        int id;
        string name, contactInfo;

        cout << "Enter Supplier ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Supplier Name: ";
        getline(cin, name);

        cout << "Enter Supplier Contact Info: ";
        getline(cin, contactInfo);

        Supplier newSupplier(id, name, contactInfo);
        addSupplier(newSupplier);
    }

    void createCustomer() {
        int id;
        string name, address, email;

        cout << "Enter Customer ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Customer Address: ";
        getline(cin, address);

        cout << "Enter Customer Email: ";
        getline(cin, email);

        Customer newCustomer(id, name, address, email);
        addCustomer(newCustomer);
    }

    void addStock() {
        int productId, quantity;

        cout << "Enter Product ID: ";
        cin >> productId;

        for (int i = 0; i < inventory.size; ++i) {
            if (inventory.products[i].id == productId) {
                cout << "Enter Quantity to Add: ";
                cin >> quantity;
                inventory.addStock(productId, quantity);
                cout << "Stock added successfully!" << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void removeStock() {
        int productId, quantity;

        cout << "Enter Product ID: ";
        cin >> productId;

        for (int i = 0; i < inventory.size; ++i) {
            if (inventory.products[i].id == productId) {
                cout << "Enter Quantity to Remove: ";
                cin >> quantity;
                inventory.removeStock(productId, quantity);
                cout << "Stock removed successfully!" << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void placeOrder() {
        int customerId, productId, quantity;

        cout << "Enter Customer ID: ";
        cin >> customerId;

        // Search for the customer
        Customer* customer = nullptr;
        for (int i = 0; i < customerCount; ++i) {
            if (customers[i].id == customerId) {
                customer = &customers[i];
                break;
            }
        }

        if (customer == nullptr) {
            cout << "Error: Customer not found!" << endl;
            return;
        }

        cout << "Enter Product ID: ";
        cin >> productId;

        // Search for the product
        Product* product = nullptr;
        int productIndex = -1;
        for (int i = 0; i < inventory.size; ++i) {
            if (inventory.products[i].id == productId) {
                product = &inventory.products[i];
                productIndex = i;
                break;
            }
        }

        if (product == nullptr) {
            cout << "Error: Product not found!" << endl;
            return;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;

        // Check if enough stock is available
        if (inventory.quantities[productIndex] < quantity) {
            cout << "Error: Not enough stock available!" << endl;
            return;
        }

        // Create and add the order
        Order newOrder(1, customer, nullptr); // Assuming supplier is not needed for now
        newOrder.products = product;
        newOrder.quantity = quantity;
        newOrder.totalPrice = product->price * quantity;
        newOrder.status = "Pending";

        // Add the order to a list of orders (not implemented in this example)

        // Update inventory
        inventory.removeStock(productId, quantity);

        cout << "Order placed successfully!" << endl;
    }
};

int main() {
    // Create a SCManager
    SCManager manager(100, 10, 100);

    int choice;
    do {
        cout << "Supply Chain Management System\n";
        cout << "1. Create Product\n2. Create Supplier\n3. Create Customer\n4. Print Products\n5. Add Stock\n6. Remove Stock\n7. Place Order\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.createProduct();
                break;
            case 2:
                manager.createSupplier();
                break;
            case 3:
                manager.createCustomer();
                break;
            case 4:
                manager.printProducts();
                break;
            case 5:
                manager.addStock();
                break;
            case 6:
                manager.removeStock();
                break;
            case 7:
                manager.placeOrder();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
