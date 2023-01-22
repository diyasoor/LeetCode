Given a string s, partition s such that every substring of the partition 
is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
 
Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
  
class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start<=end) {
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void func(int start, string s, vector<vector<string>>& ans, vector<string>& v) {
        if(start==s.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=start;i<s.size();i++) {
            if(isPalindrome(s,start,i)) {
                v.push_back(s.substr(start,i-start+1));
                func(i+1, s, ans, v);
                v.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        func(0, s, ans, v);
        return ans;
    }
};
