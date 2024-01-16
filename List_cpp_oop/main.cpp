#include <iostream>
#include "list.h"

int main() {
    LinkedList<int> linkedList;

    char choice;
    int value;
    int position;
    int oldValue, newValue;
    int count; 

    do {
        cout << "1. Add to Head\n";
        cout << "2. Add to Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Position\n";
        cout << "5. Find Element\n";
        cout << "6. Replace Element\n";
        cout << "7. Reverse List\n";
        cout << "8. Delete All\n";
        cout << "9. Show\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter value: ";
            cin >> value;
            linkedList.AddToHead(value);
            break;
        case '2':
            cout << "Enter value: ";
            cin >> value;
            linkedList.AddToTail(value);
            break;
        case '3':
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            linkedList.InsertAtPosition(value, position);
            break;
        case '4':
            cout << "Enter position: ";
            cin >> position;
            linkedList.DeleteAtPosition(position);
            break;
        case '5':
            cout << "Enter value to find: ";
            cin >> value;
            position = linkedList.Find(value);
            if (position != -1) {
                cout << "Element found at position " << position << endl;
            }
            else {
                cout << "Element not found.\n";
            }
            break;
        case '6':
            cout << "Enter old value to replace: ";
            cin >> oldValue;
            cout << "Enter new value: ";
            cin >> newValue;
            count = linkedList.Replace(oldValue, newValue);
            cout << count << " occurrences replaced.\n";
            break;
        case '7':
            linkedList.Reverse();
            cout << "List reversed.\n";
            break;
        case '8':
            linkedList.DeleteAll();
            cout << "All elements deleted.\n";
            break;
        case '9':
            linkedList.Show();
            break;
        case '0':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != '0');

    return 0;
}