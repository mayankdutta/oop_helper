#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> ans;
    int i = l;
    int j = mid;

    while (i < mid and j <= r) {
        if (arr[i] < arr[j])
            ans.push_back(arr[i++]);
        else
            ans.push_back(arr[j++]);
    }

    while (i < mid) ans.push_back(arr[i++]);
    while (j <= r) ans.push_back(arr[j++]);

    int k = 0;
    for (i = l; i <= r; i++) {
        arr[i] = ans[k++];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r - 1) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid - 1);
        mergeSort(arr, mid, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    vector<int> arr{1, 4, 0, 9, 10, INT_MIN, INT_MAX};
    mergeSort(arr, 0, arr.size() - 1);
    for (const auto &i: arr) {
        cout << i << ' ';
    }
    cout << '\n';
}
