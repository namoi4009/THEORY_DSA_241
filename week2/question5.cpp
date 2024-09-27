#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(2^n * n), where n is the number of elements in the input array.
// The function generates 2^n subsets, and for each subset, copying elements to a new array takes O(n) time.

template <typename T>
vector<vector<T>> powerSet(vector<T> arr) {
    vector<vector<T>> result;
    int n = arr.size();
    int powerSetSize = 1 << n; // 2^n

    for (int i = 0; i < powerSetSize; ++i) {
        vector<T> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back(arr[j]);
            }
        }
        result.push_back(subset);
    }

    return result;
}