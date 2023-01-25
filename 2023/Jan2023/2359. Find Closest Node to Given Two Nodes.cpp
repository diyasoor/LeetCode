You are given a directed graph of n nodes numbered from 0 to n - 1, 
where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, 
indicating that there is a directed edge from node i to node edges[i]. 
  If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, 
such that the maximum between the distance from node1 to that node, and 
from node2 to that node is minimized. If there are multiple answers, 
return the node with the smallest index, and if no possible answer exists, 
return -1.

Note that edges may contain cycles.

Example 1:
Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance 
from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot 
get a node with a smaller maximum distance than 1, so we return node 2.
  
Constraints:

n == edges.length
2 <= n <= 10^5
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n

// Time: O(n)
// Space: O(n)
  
class Solution {
public:
    void dfs(int d, int node, vector<int>&edges, vector<int>&visited, vector<int>&distances) {
        if(node!=-1 && !visited[node]) {
            visited[node]=1;
            distances[node]=d;
            dfs(d+1,edges[node],edges,visited,distances);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> fromNode1(n,-1);
        vector<int> fromNode2(n,-1);
        
        vector<int> visited(n,0);
        dfs(0,node1,edges,visited,fromNode1);
        
        visited.assign(n,0);
        dfs(0,node2,edges,visited,fromNode2);

        int minDis=n, ans=-1;
        for(int i=0;i<n;i++) {
            if(fromNode1[i]!=-1 && fromNode2[i]!=-1) {
                int maxVal=max(fromNode1[i], fromNode2[i]);
                if(maxVal < minDis) {
                    minDis = maxVal;
                    ans=i;
                }
            }
        }
        return ans;
    }
};
