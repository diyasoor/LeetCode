Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time 
complexity and with the smallest space complexity possible.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed 
(for example, 2 and 3), while the positions of other numbers are changed (for 
example, 1 and 5).

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 
Constraints:
1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4

class Solution {
public:
    void merge(vector<int> &a, int s, int mid, int e, vector<int> &temp) {
        int l = s;
        int r = mid + 1;
        int n1 = mid - s + 1;
        int n2 = e - mid;
        
        for (int i = 0; i < n1; i++) {
            temp[l + i] = a[l + i];
        }
        for (int i = 0; i < n2; i++) {
            temp[r + i] = a[r + i];
        }

        int i = 0, j = 0, k = s;
        while (i < n1 && j < n2) {
            if (temp[l + i] <= temp[r + j]) {
                a[k] = temp[l + i];
                i += 1;
            } else {
                a[k] = temp[r + j];
                j += 1;
            }
            k += 1;
        }

        while (i < n1) {
            a[k] = temp[l + i];
            i += 1;
            k += 1;
        }
        while (j < n2) {
            a[k] = temp[r + j];
            j += 1;
            k += 1;
        }
    }

    void mergesort(vector<int> &nums, int s, int e, vector<int> &temp) {
        if (s >= e) return;
        int mid = (s + e) / 2;
        mergesort(nums, s, mid, temp);
        mergesort(nums, mid + 1, e, temp);
        merge(nums, s, mid, e, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergesort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};
