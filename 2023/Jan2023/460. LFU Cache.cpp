Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not 
already present. When the cache reaches its capacity, it should invalidate and remove the least 
frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two
or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. 
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3

Constraints:
0 <= capacity <= 10^4
0 <= key <= 10^5
0 <= value <= 10^9
At most 2 * 10^5 calls will be made to get and put.
  
struct Node {
    int key, val, cnt;
    Node *next, *prev;
    Node(int k, int v) {
        key=k;
        val=v;
        cnt=1;  
    }
};
struct List {
    int size;
    Node* head, *tail;
    List() {
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addNodeFront(Node *node) {
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }
    void deleteNodeRear(Node* node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        size--;
    }
};
class LFUCache {
    unordered_map<int, Node*> keyAddress;
    unordered_map<int, List*> freqList;
    int capacity, leastFreq, currSize;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        leastFreq=0, currSize=0;
    }
    void updateFreqList(Node* node) {
        keyAddress.erase(node->key);
        freqList[node->cnt]->deleteNodeRear(node);
        
        // if the updated node has the least freq
        // and if the list had only the current element
        // then leastFreq should increase by 1
        if(node->cnt==leastFreq && freqList[node->cnt]->size==0) leastFreq++;
        
        // prepare the next higher frequency list
        List *nextFreqList=new List();
        // if the required higher frequency list already exists
        if(freqList.count(node->cnt+1)!=0) {
            nextFreqList = freqList[node->cnt + 1];
        }
        node->cnt+=1;
        nextFreqList->addNodeFront(node);
        
        // put the updated values
        keyAddress[node->key] = node;
        freqList[node->cnt] = nextFreqList;
    }
    
    int get(int key) {
        if(keyAddress.count(key)!=0) {
            Node *node=keyAddress[key];
            int data=node->val;
            // as the element is accessed 
            // change it's frequency
            updateFreqList(node);
            return data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        
        // if it is already present in the hashmap
        // and it ahs new value then update the value
        // and the frequency
        if(keyAddress.count(key)!=0) {
            Node *node = keyAddress[key];
            node->val = value;
            updateFreqList(node);
        }
        else {
            if(currSize==capacity) {
                // perform LRU which will be at 
                // the end of the leastFreq List
                List *list = freqList[leastFreq];
                Node *delNode = list->tail->prev;
                
                keyAddress.erase(delNode->key);
                freqList[leastFreq]->deleteNodeRear(delNode);
                currSize--;
            }
            currSize++;
            leastFreq=1;
            List *newList = new List();
            // if already this freq list is present
            if(freqList.count(leastFreq)!=0) {
                newList = freqList[leastFreq];
            }
            Node *newNode = new Node(key, value);
            newList->addNodeFront(newNode);
            
            keyAddress[key] = newNode;
            freqList[leastFreq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
