You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:
abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), 
columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.

Exampl:
Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.
 
Constraints:

n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 1000
strs[i] consists of lowercase English letters.
  
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        int n = strs.size();
        int cnt=0;
        for(int j=0;j<m;j++) {
            for(int i=1;i<n;i++) {
                if(strs[i-1][j] > strs[i][j]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
