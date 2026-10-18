#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int x) {
    // Fix: Handle negative inputs safely to avoid out-of-bounds array tracking
    int index = (x % SIZE + SIZE) % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            cout << "Hash table is full\n";
            return;
        }
    }

    hashTable[index] = x;
    cout << x << " inserted\n";
}

void search(int x) {
    // Fix: Handle negative inputs safely to avoid out-of-bounds array tracking
    int index = (x % SIZE + SIZE) % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == x) {
            cout << x << " found at index " << index << "\n";
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << x << " not found\n";
}

void display() {
    cout << "Hash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << i << ": Empty\n";
        else
            cout << i << ": " << hashTable[i] << "\n";
    }
}

int main() {
    int choice, x;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    do {
        cout << "\n1. INSERT\n";
        cout << "2. SEARCH\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter choice: ";
        
        // Fix: Prevent infinite loops if a user enters characters/letters
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();            // Clear the error flag
            cin.ignore(1000, '\n'); // Clear the input buffer
            choice = 0;             // Reset choice to loop again
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                if (!(cin >> x)) {
                    cout << "Invalid account number!\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    insert(x);
                }
                break;

            case 2:
                cout << "Enter account number to search: ";
                if (!(cin >> x)) {
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    search(x);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
