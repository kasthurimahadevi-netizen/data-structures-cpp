cpp

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string item;
    Node* next;
};

Node* head = nullptr;

// Add an item
void addItem(string name) {
    Node* newNode = new Node;
    newNode->item = name;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << name << " added to shopping list.\n";
}

// Remove an item
void removeItem(string name) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->item != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << name << " not found in shopping list.\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << name << " removed from shopping list.\n";
}

// Search for an item
void searchItem(string name) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->item == name) {
            cout << name << " found in shopping list.\n";
            return;
        }
        temp = temp->next;
    }

    cout << name << " not found in shopping list.\n";
}

// Display all items
void displayItems() {
    if (head == nullptr) {
        cout << "Shopping list is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\nShopping List:\n";

    while (temp != nullptr) {
        cout << "- " << temp->item << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string name;

    do {
        cout << "\n--- SHOPPING LIST MENU ---\n";
        cout << "1. Add an item\n";
        cout << "2. Remove an item\n";
        cout << "3. Search for an item\n";
        cout << "4. Display all items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> ws;
                getline(cin, name);
                addItem(name);
                break;

            case 2:
                cout << "Enter item to remove: ";
                cin >> ws;
                getline(cin, name);
                removeItem(name);
                break;

            case 3:
                cout << "Enter item to search: ";
                cin >> ws;
                getline(cin, name);
                searchItem(name);
                break;

            case 4:
                displayItems();
                break;

            case 5:
                cout << "Exiting shopping list.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    // Free remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
