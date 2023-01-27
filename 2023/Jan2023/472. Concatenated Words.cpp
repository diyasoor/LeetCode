Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
 

Constraints:

1 <= words.length <= 10^4
1 <= words[i].length <= 30
words[i] consists of only lowercase English letters.
All the strings of words are unique.
1 <= sum(words[i].length) <= 10^5


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_map<string, int> map;
        for(auto wrd: words) map[wrd]++;
    
        for(auto x: words) {
            int n=x.size();
            vector<int> dp(n+1, 0);
            dp[0]=1; 
            for(int i=0;i<n;i++) {
                if(!dp[i]) continue;
                for(int j=i+1;j<=n;j++) {
                    if(j-i < n && map[x.substr(i, j-i)] > 0) 
                        dp[j]=1;
                }
                if(dp[n]) {
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};
