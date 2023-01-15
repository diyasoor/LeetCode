There is a tree (i.e. a connected, undirected graph with no cycles) consisting of 
n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the 
value of the ith node. You are also given a 2D integer array edges where 
edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or 
equal to the starting node (i.e. the starting node's value should be the maximum 
value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 
is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

 

Example 1:


Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
Example 2:


Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.
Example 3:


Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.
 

Constraints:

n == vals.length
1 <= n <= 3 * 104
0 <= vals[i] <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
  
class DSU {
    vector<int> parent, rank;
    public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }
    int findParent(int x) {
        if(x==parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }
    void makeUnion(int x, int y) {
        int p1=findParent(x), p2=findParent(y);
        if(p1!=p2) {
            if(rank[p1]<rank[p2]) parent[p1] = p2;
            else if(rank[p1]>rank[p2]) parent[p2] = p1;
            else {
                parent[p2]=p1;
                rank[p1]++;
            }
        }
    }
};
class Solution {

    
public:
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int>> adj(n);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // vals = [1,3,2,1,3]
        // 1: 0,3
        // 2: 2
        // 3: 1, 4
        map<int, vector<int>> valuesToNodes;
        for(int node=0;node<n;node++) {
            valuesToNodes[vals[node]].push_back(node);
        }
        
        
        DSU dsu(n);
        int goodPaths=0;
        
        for(auto [values, nodes] : valuesToNodes) {
            for(int node: nodes) {
                for(int neighbor: adj[node]) {
                    if(vals[node] >= vals[neighbor]) {
                        dsu.makeUnion(node, neighbor);
                    }
                }
            }
            
            unordered_map<int,int> grp;
            for(int u:nodes) {
                grp[dsu.findParent(u)]++;
            }
            for(auto [p, size]: grp) {
                goodPaths += (size * (size+1)/2);
            }
        }
        return goodPaths;
    }
};
