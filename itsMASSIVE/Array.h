#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class Array {
private:
    int data[MAX_SIZE];
    int size;
public:
    Array() {
        size = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            data[i] = 0;
        }
    }

    Array(int initialSize, int defaultValue = 0) {
        if (initialSize > MAX_SIZE) {
            cout << "The list is way too big for the reserved space..." << endl;
            size = MAX_SIZE;
        }
        else {
            size = initialSize;
        }

        for (int i = 0; i < size; i++) {
            data[i] = defaultValue;
        }
    }

    void fillFromKeyboard() {
        cout << "Enter the ammount of elements (Max = " << MAX_SIZE << "): ";
        cin >> size;

        if (size > MAX_SIZE) {
            cout << "Way too many elements, " << MAX_SIZE << "will be used." << endl;
            size = MAX_SIZE;
        }

        cout << "Enter the " << size << " of elements:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "data " << i << " = ";
            cin >> data[i];
        }
    }

    void fillRandom(int count, int minVal = 0, int maxVal = 100) {
        if (count > MAX_SIZE) {
            cout << "Way too many elements, " << MAX_SIZE << "will be used." << endl;
            size = MAX_SIZE;
        }
        else {
            size = count;
        }

        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            data[i] = minVal + rand() % (maxVal - minVal + 1);
        }
    }

    void print() const {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }

        cout << "Array (size: " << size << "): ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    bool edit(int index, int newValue) {
        if (index >= 0 && index < size) {
            data[index] = newValue;
            return true;
        }
        else {
            cout << "Error, index " << index << " is out of range [0, " << size - 1 << "]." << endl;
            return false;
        }
    }

    bool add(int value) {
        if (size >= MAX_SIZE) {
            cout << "Error, the array is at max capacity (Max = " << MAX_SIZE << ")" << endl;
            return false;
        }

        data[size] = value;
        size++;
        return true;
    }

    bool insertAt(int index, int value) {
        if (size >= MAX_SIZE) {
            cout << "Error, the array is at max capacity." << endl;
            return false;
        }

        if (index < 0 || index > size) {
            cout << "Error, index " << index << " is out of range [0, " << size << "]" << endl;
            return false;
        }

        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;
        return true;
    }

    bool removeAt(int index) {
        if (size == 0) {
            cout << "Error: the array is empty!" << endl;
            return false;
        }

        if (index < 0 || index >= size) {
            cout << "Error, index " << index << " is out of range [0, " << size - 1 << "]" << endl;
            return false;
        }

        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
        return true;
    }

    bool removeLast() {
        if (size > 0) {
            size--;
            return true;
        }
        else {
            cout << "Error: the array is empty!" << endl;
            return false;
        }
    }

    bool removeFirst() {
        return removeAt(0);
    }

    int removeAllByValue(int value) {
        int removedCount = 0;

        for (int i = 0; i < size; ) {
            if (data[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    data[j] = data[j + 1];
                }
                size--;
                removedCount++;
            }
            else {
                i++;
            }
        }

        return removedCount;
    }

    int get(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            cout << "Error: index is out of range!" << endl;
            return -1;
        }
    }

    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            cout << "Error: index " << index << " is out of range." << endl;
            return data[0];
        }
    }

    int getSize() const {
        return size;
    }

    int getMaxSize() const {
        return MAX_SIZE;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == MAX_SIZE;
    }

    void clear() {
        size = 0;
    }

    int findFirst(int value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    int findAll(int value, int indices[]) const {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                indices[count] = i;
                count++;
            }
        }
        return count;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            int temp = data[i];
            data[i] = data[size - 1 - i];
            data[size - 1 - i] = temp;
        }
    }

    int getMin() const {
        if (size == 0) return -1;

        int min = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        return min;
    }

    int getMax() const {
        if (size == 0) return -1;

        int max = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    int sum() const {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += data[i];
        }
        return total;
    }

    double average() const {
        if (size == 0) return 0;
        return static_cast<double>(sum()) / size;
    }
};