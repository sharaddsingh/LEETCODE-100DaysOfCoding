2) (34) Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

// i learned how to use binary search to find first and last occurances of an element.

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int l = 0, h = arr.size() - 1;
        int m, first = -1, last = -1;

        while (l <= h) {
            m = (l + h) / 2;
            if (arr[m] == target) {
                first = m;
                h = m - 1; 
            } else if (arr[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

   
        l = 0;
        h = arr.size() - 1;

       
        while (l <= h) {
            m = (l + h) / 2;
            if (arr[m] == target) {
                last = m;
                l = m + 1;  
            } else if (arr[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return {first, last};
    }
};
