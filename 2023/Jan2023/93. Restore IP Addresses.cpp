A valid IP address consists of exactly four integers separated by single dots. 
Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but 
"0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses 
that can be formed by inserting dots into s. You are not allowed to reorder or 
remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 
Constraints:
1 <= s.length <= 20
s consists of digits only.
  

// Time: O(3^n) where n=4 the maximum height possible of the decesion tree is 4
  
class Solution {
public:
    long stringToInteger(string str) {
        long temp=0;
        for(int i=0;i<str.size();i++) {
            temp = temp * 10 + str[i] - '0';
        }
        return temp;
    }
    void func(int i, string s, string IP, vector<string>& ans, int dots) {
        if(dots>4) return;
        if(dots==4 && i==s.size()) {
            ans.push_back(IP.substr(0,s.size()+3));
            return;
        }
        int n=s.size();
        if(i+3 < s.size()) n=i+3;
        for(int j=i;j<n;j++) {
            long num=stringToInteger(s.substr(i,j-i+1));
            if(num < 256 && (i==j || s[i]!='0')) {
                func(j+1,s, IP + (s.substr(i,j-i+1)) + ".", ans, dots+1);
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size() > 12) return ans;
        string temp="";
        func(0, s, temp, ans, 0);
        return ans;
    }
};
