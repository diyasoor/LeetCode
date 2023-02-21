You are given a sorted array consisting of only integers where every 
element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.
  
Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
  
Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0, e=n-1;
        
        while(s<=e) {
            int mid=(s+e)/2;
            if(mid && nums[mid]==nums[mid-1]) {
                if((mid-s)%2==0) e=mid-2;
                else s=mid+1;
            }
            else if(mid+1<n && nums[mid]==nums[mid+1]) {
                if((e-mid)%2==0) s=mid+2;
                else e=mid-1;
            }
            else return nums[mid];
        }
        return -1;
    }
};
