Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
  
Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
  
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Hash(26,0);
        vector<int> s2Hash(26,0);
        int s1len=s1.size(), s2len=s2.size();
        if(s1len > s2len) return false;
        
        int left=0, right=0;
        while(right < s1len) {
            s1Hash[s1[right]-'a'] += 1;
            s2Hash[s2[right]-'a'] += 1;
            right += 1;
        }
        right -= 1; 
        while(right<s2len) {
            if(s1Hash==s2Hash) return true;
            right+=1;
            if(right!=s2len)
                s2Hash[s2[right]-'a'] +=1;
            s2Hash[s2[left]-'a'] -=1;
            left+=1;
        }
        return false;
    }
};
