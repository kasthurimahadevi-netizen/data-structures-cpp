#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    
    // Fixed: Creates the temporary array dynamically based on the exact size needed
    int size = r - l + 1;
    int* temp = new int[size];

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    // Fixed: Used a distinct loop variable 'idx' to safely map values back 
    for (int idx = l, tempIdx = 0; idx <= r; idx++, tempIdx++) {
        a[idx] = temp[tempIdx];
    }

    delete[] temp; // Clean up dynamically allocated memory
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        // Fixed: Prevents integer overflow for extremely large arrays
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {25, 10, 45, 30, 15, 50, 20};
    int n = sizeof(a) / sizeof(a[0]); // Dynamically evaluates the exact element count

    mergeSort(a, 0, n - 1);

    cout << "Sorted weights: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
