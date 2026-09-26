Quick Reference: Binary Search

Below are compact notes and short examples for Binary Search in C++.

Binary Search

Header: #include <algorithm>

Requirement: The array must be sorted.

Complexity: O(log n)

Idea: Compare the target with the middle element and eliminate half of the search range each step.

Basic Binary Search

#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>& a, int target) {
    int left = 0;
    int right = a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) {
            return mid;
        }
        if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> a = {1, 3, 5, 7, 9};
    cout << binarySearch(a, 7); // prints: 3
}

STL binary_search()

Checks whether an element exists in a sorted range.

binary_search(a.begin(), a.end(), x);

Returns true if the element exists, otherwise false.

vector<int> a = {1, 3, 5, 7, 9};
if (binary_search(a.begin(), a.end(), 5)) {
    cout << "Found";
}

lower_bound()

Returns an iterator to the first element greater than or equal to x.

lower_bound(a.begin(), a.end(), x);

Example:

vector<int> a = {1, 3, 3, 3, 7, 9};
int index = lower_bound(a.begin(), a.end(), 3) - a.begin();
cout << index; // prints: 1

Remember:

lower_bound(x) -> first element >= x

upper_bound()

Returns an iterator to the first element greater than x.

upper_bound(a.begin(), a.end(), x);

Example:

vector<int> a = {1, 3, 3, 3, 7, 9};
int index = upper_bound(a.begin(), a.end(), 3) - a.begin();
cout << index; // prints: 4

Remember:

upper_bound(x) -> first element > x

Count Occurrences

The number of occurrences of x can be found using:

int count = upper_bound(a.begin(), a.end(), x)
          - lower_bound(a.begin(), a.end(), x);

Example:

vector<int> a = {1, 2, 2, 2, 5, 7};
int x = 2;
int count = upper_bound(a.begin(), a.end(), x)
          - lower_bound(a.begin(), a.end(), x);
cout << count; // prints: 3

Quick Cheat Sheet

// Check if x exists
binary_search(a.begin(), a.end(), x);
// First element >= x
lower_bound(a.begin(), a.end(), x);
// First element > x
upper_bound(a.begin(), a.end(), x);
// Index of first element >= x
int index = lower_bound(a.begin(), a.end(), x) - a.begin();
// First occurrence of x
int first = lower_bound(a.begin(), a.end(), x) - a.begin();
// Last occurrence of x
int last = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
// Number of occurrences of x
int count = upper_bound(a.begin(), a.end(), x)
          - lower_bound(a.begin(), a.end(), x);

Summary

Operation	Meaning	Complexity
Binary Search	Find x	O(log n)
binary_search()	Check if x exists	O(log n)
lower_bound()	First element >= x	O(log n)
upper_bound()	First element > x	O(log n)

Important: Binary Search, lower_bound(), and upper_bound() require the data to be sorted.