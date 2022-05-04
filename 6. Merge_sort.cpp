#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> ans;
    int i = l;
    int j = mid + 1;

    while (i <= mid and j <= r) {
        if (arr[i] < arr[j])
            ans.push_back(arr[i++]);
        else
            ans.push_back(arr[j++]);
    }

    while (i <= mid) ans.push_back(arr[i++]);
    while (j <= r) ans.push_back(arr[j++]);

    int k = 0;
    for (i = l; i <= r; i++) {
        arr[i] = ans[k++];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        /*
         * Don't do, mid - 1, and mid
         * Just dont
         * You will get RTE
         */
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}


int main() {
    vector<int> arr{5, 2, 3, 1};
    mergeSort(arr, 0, arr.size() - 1);
    for (const auto &i: arr) {
        cout << i << ' ';
    }
    cout << '\n';
}
