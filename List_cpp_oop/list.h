#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void AddToHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void InsertAtPosition(T value, int position) {
        Node<T>* newNode = new Node<T>(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            if (!tail) {
                tail = newNode;
            }
        }
        else {
            Node<T>* current = head;
            int currentPosition = 0;
            while (current && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }
            if (current) {
                newNode->next = current->next;
                current->next = newNode;
                if (!newNode->next) {
                    tail = newNode;
                }
            }
            else {
                cout << "Invalid position for insertion.\n";
            }
        }
    }

    void DeleteAtPosition(int position) {
        if (position == 0) {
            if (head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                if (!head) {
                    tail = nullptr;
                }
            }
        }
        else {
            Node<T>* current = head;
            int currentPosition = 0;
            while (current && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }
            if (current && current->next) {
                Node<T>* temp = current->next;
                current->next = temp->next;
                delete temp;
                if (!current->next) {
                    tail = current;
                }
            }
            else {
                cout << "Invalid position for deletion.\n";
            }
        }
    }

    int Find(T value) const {
        Node<T>* current = head;
        int position = 0;
        while (current) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    int Replace(T oldValue, T newValue) {
        Node<T>* current = head;
        int count = 0;
        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                count++;
            }
            current = current->next;
        }
        return count;
    }

    void Reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void DeleteAll() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void Show() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif