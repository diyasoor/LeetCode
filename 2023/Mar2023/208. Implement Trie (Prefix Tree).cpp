A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently 
store and retrieve keys in a dataset of strings. There are various applications of this 
data structure, such as autocomplete and spellchecker.

Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was 
inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string 
word that has the prefix prefix, and false otherwise.
 

Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:
1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
  
struct Node {
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch-'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* getNext(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private: 
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++) {
            // if not contains then we'll put it 
            // with a new reference node for further insertion
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            // it will moves to the reference trie, 
            // as it already contains the character
            node = node->getNext(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.length();i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->getNext(prefix[i]);
        }
        return true;
    }
};

