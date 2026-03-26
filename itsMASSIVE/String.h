#pragma once
#include <iostream>

class String {
private:
    char* str;
    int size;
    int capacity;

public:
    String() {
        str = new char[1];
        str[0] = '\0';
        size = 0;
        capacity = 1;
    }

    String(const char* s) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
            size = 0;
            capacity = 1;
        }
        else {
            size = 0;
            while (s[size] != '\0') {
                size++;
            }

            capacity = size + 1;
            str = new char[capacity];

            for (int i = 0; i < size; i++) {
                str[i] = s[i];
            }
            str[size] = '\0';
        }
    }

    String(const String& other) {
        size = other.size;
        capacity = other.capacity;
        str = new char[capacity];

        for (int i = 0; i < size; i++) {
            str[i] = other.str[i];
        }
        str[size] = '\0';
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;

            size = other.size;
            capacity = other.capacity;
            str = new char[capacity];

            for (int i = 0; i < size; i++) {
                str[i] = other.str[i];
            }
            str[size] = '\0';
        }
        return *this;
    }

    char& operator[](int index) {
        return str[index];
    }

    const char& operator[](int index) const {
        return str[index];
    }

    String operator+(const String& other) const {
        String result;
        delete[] result.str;

        result.size = size + other.size;
        result.capacity = result.size + 1;
        result.str = new char[result.capacity];

        for (int i = 0; i < size; i++) {
            result.str[i] = str[i];
        }

        for (int i = 0; i < other.size; i++) {
            result.str[size + i] = other.str[i];
        }

        result.str[result.size] = '\0';
        return result;
    }

    String& operator+=(const String& other) {
        int newSize = size + other.size;

        if (newSize + 1 > capacity) {
            int newCapacity = newSize + 1;
            char* newStr = new char[newCapacity];

            for (int i = 0; i < size; i++) {
                newStr[i] = str[i];
            }

            delete[] str;
            str = newStr;
            capacity = newCapacity;
        }

        for (int i = 0; i < other.size; i++) {
            str[size + i] = other.str[i];
        }

        size = newSize;
        str[size] = '\0';
        return *this;
    }

    bool operator==(const String& other) const {
        if (size != other.size) return false;

        for (int i = 0; i < size; i++) {
            if (str[i] != other.str[i]) return false;
        }
        return true;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    int length() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void clear() {
        delete[] str;
        str = new char[1];
        str[0] = '\0';
        size = 0;
        capacity = 1;
    }

    void append(char c) {
        if (size + 2 > capacity) {
            int newCapacity = capacity * 2;
            char* newStr = new char[newCapacity];

            for (int i = 0; i < size; i++) {
                newStr[i] = str[i];
            }

            delete[] str;
            str = newStr;
            capacity = newCapacity;
        }

        str[size] = c;
        size++;
        str[size] = '\0';
    }

    void insert(int pos, char c) {
        if (pos < 0 || pos > size) return;

        if (size + 2 > capacity) {
            int newCapacity = capacity * 2;
            char* newStr = new char[newCapacity];

            for (int i = 0; i < size; i++) {
                newStr[i] = str[i];
            }

            delete[] str;
            str = newStr;
            capacity = newCapacity;
        }

        for (int i = size; i > pos; i--) {
            str[i] = str[i - 1];
        }

        str[pos] = c;
        size++;
        str[size] = '\0';
    }

    void remove(int pos) {
        if (pos < 0 || pos >= size) return;

        for (int i = pos; i < size - 1; i++) {
            str[i] = str[i + 1];
        }

        size--;
        str[size] = '\0';
    }

    const char* c_str() const {
        return str;
    }

    int find(char c) const {
        for (int i = 0; i < size; i++) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    String substring(int start, int end) const {
        if (start < 0) start = 0;
        if (end > size) end = size;
        if (start >= end) return String();

        String result;
        delete[] result.str;

        result.size = end - start;
        result.capacity = result.size + 1;
        result.str = new char[result.capacity];

        for (int i = 0; i < result.size; i++) {
            result.str[i] = str[start + i];
        }
        result.str[result.size] = '\0';

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        os << s.str;
        return os;
    }
};
