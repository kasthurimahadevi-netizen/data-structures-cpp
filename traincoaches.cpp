#include <iostream> 
using namespace std; 

struct Node { 
    int coach; 
    Node* next; 
}; 

Node* head = NULL; 

void addBeginning(int n) { 
    Node* newNode = new Node; 
    newNode->coach = n; 
    newNode->next = head; 
    head = newNode; 
} 

void addEnd(int n) { 
    Node* newNode = new Node; 
    newNode->coach = n; 
    newNode->next = NULL; 
    if (head == NULL) { 
        head = newNode; 
        return; 
    } 
    Node* temp = head; 
    while (temp->next != NULL) 
        temp = temp->next; 
    temp->next = newNode; 
} 

void removeCoach() { 
    if (head == NULL) { 
        cout << "No coaches to remove\n"; 
        return; 
    } 
    Node* temp = head; 
    head = head->next; 
    delete temp; 
    cout << "Coach removed from beginning\n"; 
} 

void display() { 
    Node* temp = head; 
    if (temp == NULL) { 
        cout << "No coaches\n"; 
        return; 
    } 
    while (temp != NULL) { 
        cout << "Coach" << temp->coach << " -> "; 
        temp = temp->next; 
    } 
    cout << "NULL\n"; 
} 

int main() { 
    int choice, n; 
    do { 
        cout << "\n1. Add coach at beginning"; 
        cout << "\n2. Add coach at end"; 
        cout << "\n3. Remove coach"; 
        cout << "\n4. Display coaches"; 
        cout << "\n5. Exit"; 
        cout << "\nEnter choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                cout << "Enter coach number: "; 
                cin >> n; 
                addBeginning(n); 
                break; 
            case 2: 
                cout << "Enter coach number: "; 
                cin >> n; 
                addEnd(n); 
                break; 
            case 3: 
                removeCoach(); 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                cout << "Exiting program\n"; 
                break; 
            default: 
                cout << "Invalid choice\n"; 
        } 
    } while (choice != 5); 
    return 0; 
}
