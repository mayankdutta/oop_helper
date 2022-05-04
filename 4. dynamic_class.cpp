// for any confusion, refer to previous operator overloading file uploaded.
#include <iostream>

using namespace std;

class Array {

    int *head;
    int capacity;
    int index;

public:
    Array() : head(new int[2]), capacity(2), index(0) {}

    Array(const Array &arr) {
        this->head = new int[arr.capacity];
        for (int i = 0; i < arr.capacity; i++) {
            head[i] = arr[i];
        }
        this->index = arr.index;
        this->capacity = arr.capacity;
    }

    bool operator==(const Array &arr) {
        if (this->index != arr.index) return false;
        for (int i = 0; i < this->index; i++) {
            if (arr[i] != head[i]) {
                return false;
            }
        }
        return true;
    }

    void operator+=(int element) {
        if (index == capacity) {
            this->resize();
        }
        head[index++] = element;
    }

    void operator--(int) {
        if (index == 0)
            return;
        head[index--] = 0;
    }

    int operator[](int i) const {
        if (i >= index) {
            return -1;
        }
        return head[i];
    }

    void resize() {
        int *arr = new int[2 * this->capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = head[i];
        }
        delete[] head;
        head = arr;
        this->capacity *= 2;
    }

    friend ostream &operator<<(ostream &, Array &);
};

ostream &operator<<(ostream &COUT, Array &arr) {
    for (int i = 0; i < arr.index; i++) {
        COUT << arr[i] << ' ';
    }
    COUT << '\n';
    return COUT;
}

int main() {
    Array arr;
    arr += 1;
    arr += 2;
    arr += 3;
    cout << arr;

    arr--;
    cout << arr;

    Array arr2(arr);

    cout << "is equal: " << (arr == arr2) << '\n';
    arr2 += 0;
    cout << arr << arr2 << '\n';
    cout << "is equal: " << (arr == arr2) << '\n';
}
