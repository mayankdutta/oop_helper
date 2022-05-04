// maxheap, for 0 indexed array.

#include <iostream>
#include <vector>

using namespace std;


class Heap {
    static int parent(int n) { return n / 2; }

    static int leftChild(int n) { return 2 * n; }

    static int rightChild(int n) { return 2 * n + 1; }

    void sort() {
        for (int i = parent(H.size() - 1); i >= 0; i--) {
            ShiftDown(i);
        }
    }

    vector<int> H;

public:
    Heap(const vector<int> &arr) {
        H = arr;
        sort();
    }

    void ShiftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < H.size() and H[l] > H[maxIndex]) {
            maxIndex = l;
        }
        if (r < H.size() and H[r] > H[maxIndex]) {
            maxIndex = r;
        }
        if (i != maxIndex) {
            swap(H[i], H[maxIndex]);
            ShiftDown(maxIndex);
        }
    }

    void shiftUp(int i) {
        while (0 <= i and H[parent(i)] < H[i]) {
            swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    int extractMax() {
        int result = H[0];
        H[0] = H.back();
        H.pop_back();
        ShiftDown(0);
        return result;
    }

    void insert(int p) {
        H.push_back(p);
        shiftUp(H.size() - 1);
    }

    void remove(int i) {
        H[i] = INT_MAX;
        shiftUp(i);
        extractMax();
    }

    void display() {
        for (const auto &i: H) {
            cout << i << ' ';
        }
        cout << '\n';
    }
};

int main() {
    vector<int> arr{1, 4, 0, 9, 10};
    Heap h(arr);
    h.display();

    cout << h.extractMax() << '\n';
    h.display();
}
