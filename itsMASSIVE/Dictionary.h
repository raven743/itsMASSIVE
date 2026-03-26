#pragma once
#include <iostream>

template<typename K, typename V>
class Dictionary {
private:
    K* keys;
    V* values;
    int size;
    int capacity;

public:
    Dictionary() {
        capacity = 10;
        size = 0;
        keys = new K[capacity];
        values = new V[capacity];
    }

    ~Dictionary() {
        delete[] keys;
        delete[] values;
    }

    void Add(K key, V value) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }

        if (size < capacity) {
            keys[size] = key;
            values[size] = value;
            size++;
        }
        else {
            std::cout << "Dictionary noJloH!1!!" << std::endl;
        }
    }

    V Get(K key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        std::cout << "Key not found..." << std::endl;
        return V();
    }

    void Remove(K key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                for (int j = i; j < size - 1; j++) {
                    keys[j] = keys[j + 1];
                    values[j] = values[j + 1];
                }
                size--;
                return;
            }
        }
        std::cout << "Key not found, cancelling the deletion." << std::endl;
    }

    bool ContainsKey(K key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                return true;
            }
        }
        return false;
    }

    int Count() {
        return size;
    }

    void Clear() {
        size = 0;
    }

    void Print() {
        for (int i = 0; i < size; i++) {
            std::cout << "Key = " << keys[i] << " = Value = " << values[i] << std::endl;
        }
    }
};
