class Solution {
public:
    int getPivotIndex(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid is the pivot
            if (mid + 1 < n && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid - 1 >= 0 && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }

            // Decide whether to go left or right
            if (arr[s] > arr[mid]) {
                e = mid - 1; // Move left
            } else {
                s = mid + 1; // Move right
            }
        }
        return -1; // No pivot found
    }

    int binarySearch(vector<int>& arr, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid; // Target found
            } else if (arr[mid] < target) {
                s = mid + 1; // Search in the right half
            } else {
                e = mid - 1; // Search in the left half
            }
        }
        return -1; // Target not found
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Handle edge case: empty array
        if (n == 0) {
            return -1;
        }

        int pivotIndex = getPivotIndex(nums);

        // If array is not rotated, do a normal binary search
        if (pivotIndex == -1) {
            return binarySearch(nums, target, 0, n - 1);
        }

        // If target lies in the left part
        if (target >= nums[0] && target <= nums[pivotIndex]) {
            return binarySearch(nums, target, 0, pivotIndex);
        }

        // If target lies in the right part
        if (pivotIndex + 1 < n && target >= nums[pivotIndex + 1] && target <= nums[n - 1]) {
            return binarySearch(nums, target, pivotIndex + 1, n - 1);
        }

        return -1; // Target not found
    }
};
