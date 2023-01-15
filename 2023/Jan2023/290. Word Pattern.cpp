Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.


class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> v;
        int i=0;
        string temp="";
        while(i < s.size()) {
            if(s[i] == ' ') {
                v.push_back(temp);
                temp = "";
            }
            else temp += s[i];
            i++;
        }
        v.push_back(temp);
        if(v.size()!=p.size()) return false;
        
        unordered_map<char, string> map;
        set<string> visited;
        for(int i=0;i<p.size();i++) {
            if(map.find(p[i])!=map.end()) {
                if(map[p[i]] != v[i]) return false;
            }
            else {
                if(visited.count(v[i])) return false;
                map[p[i]] = v[i];
                visited.insert(v[i]);
            }
        }
        return true;
    }
};
