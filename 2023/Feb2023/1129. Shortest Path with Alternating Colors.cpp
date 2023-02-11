You are given an integer n, the number of nodes in a directed graph where the 
nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, 
and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node 
ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node 
uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the 
shortest path from node 0 to node x such that the edge colors alternate along 
the path, or -1 if such a path does not exist.

 

Example 1:
Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]

Example 2:
Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]
 
Constraints:
1 <= n <= 100
0 <= redEdges.length, blueEdges.length <= 400
redEdges[i].length == blueEdges[j].length == 2
0 <= ai, bi, uj, vj < n

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto r:red) adj[r[0]].push_back({r[1], 1}); // red: 1
        for(auto b:blue) adj[b[0]].push_back({b[1], 2});// blue: 2
        
        vector<int> distance(n, -1);
        
        queue<vector<int>> q;
        // {starting node, distance, edgeColor}
        q.push({0,0,-1});
        
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            
            int node=curr[0], nodeDis=curr[1], color=curr[2];
            
            // put the current distance to reach this node
            if(distance[node]==-1) distance[node]=nodeDis;
            
            // traverse all the neighbours
            for(auto &ch: adj[node]) {
                int childNode=ch.first, childColor=ch.second;
                
                if(childNode!=-1 && (color==-1 || color!=childColor)) {
                    q.push({childNode, nodeDis+1, childColor});
                    // mark as visited to avoid looping
                    ch.first=-1;
                }
            }
        }
        return distance;
    }
};
