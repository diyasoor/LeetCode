You are given an array of k linked-lists lists, each linked-list 
is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []
 
Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
  
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(ListNode* x: lists) {
            if(x) pq.push(x); 
        }
        while(!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();
            
            if(head==NULL) {
                head = temp;
                tail = head; 
            }
            else {
                tail->next = temp;
                tail = temp;
            }
            if(temp->next) pq.push(temp->next);
        }
        return head;
    }
};
