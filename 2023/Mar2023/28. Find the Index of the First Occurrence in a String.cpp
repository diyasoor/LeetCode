Given two strings needle and haystack, return the index of the first 
occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.
  
class Solution {
public:
    bool isSame(int j, string h, string n) {
        int i;
        for(i=1;i<n.size();i++) {
            if(n[i]!=h[j]) return false;
            j++;
        }
        if(i==n.size()) return true;
        return false;
    }
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(haystack==needle) return 0;
        if(needle.size() > haystack.size()) return -1;
        
        bool flag=false;
        int ansIdx;
        
        for(int i=0;i<haystack.size();i++) {
            if(haystack[i]==needle[0]) {
                ansIdx=i;
                flag=isSame(i+1, haystack, needle);
                if(flag) break;
            }
        }
        return flag ? ansIdx : -1;
    }
};
