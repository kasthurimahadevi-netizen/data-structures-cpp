cpp

#include <iostream>
using namespace std;

int main()
{
    string a[100], item;
    int n = 0, ch, i, j, found;

    do
    {
        cout << "\n1.Add Item";
        cout << "\n2.Remove Item";
        cout << "\n3.Search Item";
        cout << "\n4.Display Items";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter item: ";
                cin >> a[n];
                n++;
                cout << "Item added";
                break;

            case 2:
                cout << "Enter item to remove: ";
                cin >> item;
                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(a[i] == item)
                    {
                        for(j = i; j < n-1; j++)
                            a[j] = a[j+1];

                        n--;
                        found = 1;
                        cout << "Item removed";
                        break;
                    }
                }

                if(found == 0)
                    cout << "Item not found";
                break;

            case 3:
                cout << "Enter item to search: ";
                cin >> item;
                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(a[i] == item)
                    {
                        found = 1;
                        cout << "Item found";
                        break;
                    }
                }

                if(found == 0)
                    cout << "Item not found";
                break;

            case 4:
                cout << "Shopping List:\n";
                for(i = 0; i < n; i++)
                    cout << a[i] << "\n";
                break;

            case 5:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(ch != 5);

    return 0;
}
Sample Output

text
1.Add Item
2.Remove Item
3.Search Item
4.Display Items
5.Exit
Enter choice: 1
Enter item: Milk
Item added

Enter choice: 1
Enter item: Rice
Item added

Enter choice: 4
Shopping List:
Milk
Rice

Enter choice: 3
Enter item to search: Milk
Item found
