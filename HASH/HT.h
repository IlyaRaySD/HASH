#pragma once
using namespace std;
#include <string>
#include <iostream>
#define TABLE_SIZE 23

struct HashNode {
    string key;
    string value;
    HashNode* next;

    HashNode(const string& key, const string& value) : key(key), value(value), next(nullptr) {}
};

class HT {
private:
    HashNode* table[TABLE_SIZE];

    // Hash function
    int hash(const string& key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue += c;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    HT() {
        // Initializing array elements
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Method for inserting an element into a hash table
    void insert(const string& key, const string& value) {
        int index = hash(key);
        HashNode* newNode = new HashNode(key, value);

        if (table[index] == nullptr) {
            // If there is no collision, simply insert the element
            table[index] = newNode;
        }
        else {
            // If there is a collision, add it to the end of the chain
            HashNode* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Method for delete the element
    void remove(const string& key) {
        int index = hash(key);
        HashNode* current = table[index];
        HashNode* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    // If the element to be removed is the first in the chain
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Key '" << key << "' was removed successfully." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Key '" << key << "' wasn't found." << endl;
    }

    // Method for getting value by key
    string get(const string& key) {
        int index = hash(key);
        HashNode* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        return "Key wasn't found";
    }

    void show() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* current = table[i];
            cout << "index " << i;
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ")";
                current = current->next;
            }
            cout << "\n";
        }
    }
};