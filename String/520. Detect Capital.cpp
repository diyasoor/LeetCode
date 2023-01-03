We define the usage of capitals in a word to be right when one of the following cases holds:

🛑 All letters in this word are capitals, like "USA".
🛑 All letters in this word are not capitals, like "leetcode".
🛑 Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.

Example 1:

Input: word = "USA"
Output: true
  
Example 2:

Input: word = "FlaG"
Output: false
 
Constraints:
1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

class Solution {
public:
    bool UpperAll(int i, string word) {
        while(i<word.size()) {
            if(islower(word[i]))
                return false;
            i++;
        }
        return true;
    }
    bool LowerAll(int i, string word) {
        while(i<word.size()) {
            if(isupper(word[i]))
                return false;
            i++;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(isupper(word[0])) {
            if(UpperAll(1, word) || LowerAll(1, word)) 
                return true; 
        }
        else if(LowerAll(1, word)) 
            return true;
        return false;
    }
};
