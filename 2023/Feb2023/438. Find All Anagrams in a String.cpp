Given two strings s and p, return an array of all the start indices of 
p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a 
different word or phrase, typically using all the original letters 
exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:
1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.
  
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sHash(26,0);
        vector<int> pHash(26,0);
        
        int totalLen=s.size(), windowLen=p.size();
        
        if(totalLen < windowLen) return {};
        
        int left=0, right=0;
        while(right < windowLen) {
            sHash[s[right]-'a'] += 1;
            pHash[p[right]-'a'] += 1;
            right++;
        }
        right--;
        vector<int> ans;
        while(right < totalLen) {
            if(sHash==pHash) ans.push_back(left);
            // increase the window from right by 1
            right++;
            if(right < totalLen) sHash[s[right]-'a']++;
            // decrease the window from left by 1
            sHash[s[left]-'a']--;
            left++;
        }
        return ans;
    }
};
