Given an integer array nums, return all the different possible non-decreasing 
subsequences of the given array with at least two elements. You may return 
the answer in any order.

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
 

Constraints:
1 <= nums.length <= 15
-100 <= nums[i] <= 100
  
// T.C = O(2^N)
// S.C = O(N)
class Solution {
public:
    void solve(int i, vector<int>&nums,vector<int>& temp, set<vector<int>>& set) {
        if(i==nums.size()) {
            if(temp.size()>=2) set.insert(temp);
            return;
        }
        if(temp.size()==0 || temp.back() <= nums[i]) {
            temp.push_back(nums[i]);
            solve(i+1, nums, temp, set);
            temp.pop_back();
        }
        solve(i+1, nums, temp, set);
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> set;
        vector<int> v;
        solve(0,nums,v,set);
        vector<vector<int>> ans;
        for(auto v:set) {
            ans.push_back(v);
        }
        return ans;
    }
};
