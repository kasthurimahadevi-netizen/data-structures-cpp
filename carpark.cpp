#include <iostream>
using namespace std;

int main() {
    int stack[100], top = -1;
    int choice, car;

    do {
        cout << "\n1. Park a car";
        cout << "\n2. Remove a car";
        cout << "\n3. Display parked cars";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        
        // Prevent infinite loop if user inputs a character instead of an integer
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();            // Clear the error flag
            cin.ignore(1000, '\n'); // Discard the invalid input string
            continue;
        }

        switch (choice) {
            case 1:
                if (top == 99) {
                    cout << "Parking is full!\n";
                } else {
                    cout << "Enter car number: ";
                    if (!(cin >> car)) {
                        cout << "Invalid car number!\n";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    } else {
                        stack[++top] = car;
                        cout << "Car parked successfully\n";
                    }
                }
                break;

            case 2:
                if (top == -1) {
                    cout << "Parking is empty!\n";
                } else {
                    cout << "Car removed: " << stack[top--] << endl;
                }
                break;

            case 3:
                if (top == -1) {
                    cout << "Parking is empty!\n";
                } else {
                    cout << "Parked cars: ";
                    for (int i = top; i >= 0; i--)
                        cout << stack[i] << " ";
                    cout << endl;
                }
                break;

            case 4:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
