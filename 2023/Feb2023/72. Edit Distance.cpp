Given two strings word1 and word2, return the minimum number of 
operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
  
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=word1.size();
        int w2=word2.size();
        
        vector<vector<int>> dp(w1+1, vector<int>(w2+1));
        
        for(int i=0;i<=w1;i++) {
            dp[i][w2]=w1-i;
        }
        for(int i=0;i<=w2;i++) {
            dp[w1][i]=w2-i;
        }
        
        for(int i=w1-1;i>=0;i--) {
            for(int j=w2-1;j>=0;j--) {
                if(word1[i]==word2[j]) {
                    dp[i][j]=dp[i+1][j+1];
                }
                else {
                    dp[i][j]=1+min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
