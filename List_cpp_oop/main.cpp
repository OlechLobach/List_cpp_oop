#include "List.h"

int main() {
    LinkedList<int> linkedList;

    char choice;
    int value;

    do {
        cout << "1. Add to Head\n";
        cout << "2. Add to Tail\n";
        cout << "3. Delete from Head\n";
        cout << "4. Delete from Tail\n";
        cout << "5. Delete All\n";
        cout << "6. Show\n";
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
            linkedList.DeleteFromHead();
            break;
        case '4':
            linkedList.DeleteFromTail();
            break;
        case '5':
            linkedList.DeleteAll();
            break;
        case '6':
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