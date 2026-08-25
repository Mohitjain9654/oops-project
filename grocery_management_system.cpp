#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class GroceryItem {
public:
    int id;
    string name;
    int quantity;
    float price;

    GroceryItem(int id, string name, int quantity, float price) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
};

class GroceryManagementSystem {
private:
    vector<GroceryItem> items;
    int nextId = 1;

public:

    // Add Grocery Item
    void addItem() {
        string name;
        int quantity;
        float price;

        cout << "\nEnter item name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter price per item: ";
        cin >> price;

        items.push_back(GroceryItem(nextId, name, quantity, price));

        cout << "\nItem added successfully! ID: " << nextId << endl;
        nextId++;
    }

    // Display All Items
    void displayItems() {
        if (items.empty()) {
            cout << "\nNo grocery items available.\n";
            return;
        }

        cout << "\n-------------------------------------------------\n";
        cout << left
             << setw(5) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Quantity"
             << setw(10) << "Price" << endl;

        cout << "-------------------------------------------------\n";

        for (auto item : items) {
            cout << left
                 << setw(5) << item.id
                 << setw(20) << item.name
                 << setw(10) << item.quantity
                 << setw(10) << item.price
                 << endl;
        }
    }

    // Search Item
    void searchItem() {
        int id;

        cout << "\nEnter Item ID to search: ";
        cin >> id;

        for (auto item : items) {
            if (item.id == id) {
                cout << "\nItem Found!\n";
                cout << "Name: " << item.name << endl;
                cout << "Quantity: " << item.quantity << endl;
                cout << "Price: " << item.price << endl;
                return;
            }
        }

        cout << "\nItem not found!\n";
    }

    // Update Quantity
    void updateItem() {
        int id, newQuantity;

        cout << "\nEnter Item ID: ";
        cin >> id;

        for (auto &item : items) {
            if (item.id == id) {
                cout << "Enter new quantity: ";
                cin >> newQuantity;

                item.quantity = newQuantity;

                cout << "\nItem updated successfully!\n";
                return;
            }
        }

        cout << "\nItem not found!\n";
    }

    // Delete Item
    void deleteItem() {
        int id;

        cout << "\nEnter Item ID to delete: ";
        cin >> id;

        for (int i = 0; i < items.size(); i++) {
            if (items[i].id == id) {
                items.erase(items.begin() + i);

                cout << "\nItem deleted successfully!\n";
                return;
            }
        }

        cout << "\nItem not found!\n";
    }

    // Calculate Total Inventory Value
    void calculateTotalValue() {
        float total = 0;

        for (auto item : items) {
            total += item.quantity * item.price;
        }

        cout << fixed << setprecision(2);
        cout << "\nTotal Grocery Inventory Value: Rs. "
             << total << endl;
    }

    // Main Menu
    void menu() {
        int choice;

        do {
            cout << "\n\n========== GROCERY MANAGEMENT SYSTEM ==========\n";
            cout << "1. Add Grocery Item\n";
            cout << "2. Display All Items\n";
            cout << "3. Search Item\n";
            cout << "4. Update Item Quantity\n";
            cout << "5. Delete Item\n";
            cout << "6. Calculate Total Inventory Value\n";
            cout << "0. Exit\n";

            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addItem();
                    break;

                case 2:
                    displayItems();
                    break;

                case 3:
                    searchItem();
                    break;

                case 4:
                    updateItem();
                    break;

                case 5:
                    deleteItem();
                    break;

                case 6:
                    calculateTotalValue();
                    break;

                case 0:
                    cout << "\nThank you for using Grocery Management System!\n";
                    break;

                default:
                    cout << "\nInvalid choice! Please try again.\n";
            }

        } while (choice != 0);
    }
};

int main() {
    GroceryManagementSystem grocerySystem;

    grocerySystem.menu();

    return 0;
}
