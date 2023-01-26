There are n cities connected by some number of flights. You are given an array 
flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight 
from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price 
from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
  
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto fl:flights) {
            adj[fl[0]].push_back({fl[1], fl[2]});
        }
        // {stops, node, cost}
        queue<vector<int>> q;
        q.push({0, src, 0});
        vector<int> cost(n, INT_MAX);
        cost[src]=0;
        while(!q.empty()) {
            auto temp=q.front();
            q.pop();
            
            int stops=temp[0];
            int node=temp[1];
            int price=temp[2];
            
            if(stops > k) continue;
            for(auto it: adj[node]) {
                int adjNode=it.first;
                int edgeWeight=it.second;
                
                int newCost=price+edgeWeight;
                
                if(newCost < cost[adjNode] && stops<=k) {
                    cost[adjNode] = newCost;
                    q.push({stops+1, adjNode, newCost});
                }
            }
        }
        
        if(cost[dst]==INT_MAX) return -1;
        return cost[dst];
    }
};
