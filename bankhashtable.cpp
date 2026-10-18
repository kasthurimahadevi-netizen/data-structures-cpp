#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void insert(int x) {
    // Fix: Handle negative inputs safely to avoid out-of-bounds indexing
    int index = (x % SIZE + SIZE) % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index] = x;
    printf("%d inserted\n", x);
}

void search(int x) {
    // Fix: Handle negative inputs safely to avoid out-of-bounds indexing
    int index = (x % SIZE + SIZE) % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == x) {
            printf("%d found at index %d\n", x, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("%d not found\n", x);
}

void display() {
    printf("Hash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("%d: Empty\n", i);
        else
            printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, x;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    while (1) {
        printf("\n1. INSERT\n2. SEARCH\n3. DISPLAY\n4. EXIT\n");
        printf("Enter choice: ");
        
        // Fix: Validate choice input to prevent infinite loops from string characters
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                if (scanf("%d", &x) == 1) {
                    insert(x);
                } else {
                    printf("Invalid account number!\n");
                    while (getchar() != '\n');
                }
                break;

            case 2:
                printf("Enter account number to search: ");
                if (scanf("%d", &x) == 1) {
                    search(x);
                } else {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                }
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
