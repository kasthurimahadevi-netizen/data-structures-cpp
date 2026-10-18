#include <iostream>
#include <string>

using namespace std;

int main() {
    string a[100], item;
    int n = 0, ch, i, j, found;

    do {
        cout << "\n1.Add Item";
        cout << "\n2.Remove Item";
        cout << "\n3.Search Item";
        cout << "\n4.Display Items";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                if (n >= 100) {
                    cout << "List is full! Cannot add more items.";
                } else {
                    cout << "Enter item: ";
                    cin >> a[n];
                    n++;
                    cout << "Item added";
                }
                break;

            case 2:
                cout << "Enter item to remove: ";
                cin >> item;
                found = 0;
                for(i = 0; i < n; i++) {
                    if(a[i] == item) {
                        // Shift elements to the left
                        for(j = i; j < n - 1; j++) {
                            a[j] = a[j+1];
                        }
                        n--;
                        found = 1;
                        cout << "Item removed";
                        break; // Exit the loop after removing the item
                    }
                }
                if(found == 0) {
                    cout << "Item not found";
                }
                break;

            case 3:
                cout << "Enter item to search: ";
                cin >> item;
                found = 0;
                for(i = 0; i < n; i++) {
                    if(a[i] == item) {
                        found = 1;
                        cout << "Item found at position " << i + 1;
                        break;
                    }
                }
                if(found == 0) {
                    cout << "Item not found";
                }
                break;

            case 4:
                if (n == 0) {
                    cout << "Shopping List is empty!";
                } else {
                    cout << "Shopping List:\n";
                    for(i = 0; i < n; i++) {
                        cout << i + 1 << ". " << a[i] << "\n";
                    }
                }
                break;

            case 5:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice! Please try again.";
        }
        cout << "\n"; // Adds a newline for cleaner output formatting
    } while(ch != 5);

    return 0;
}
