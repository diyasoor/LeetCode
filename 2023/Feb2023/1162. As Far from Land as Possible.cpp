Given an n x n grid containing only values 0 and 1, where 0 represents water 
and 1 represents land, find a water cell such that its distance to the nearest 
land cell is maximized, and return the distance. If no land or water exists 
in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance 
between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
  
Example 2:
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 
Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
  
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        
        vector<vector<int>> dir{{0,1}, {1,0}, {-1,0}, {0,-1}};
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<vector<int>> q;
        
        // push the lands into the queue
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int ans=-1;
        while(!q.empty()) {
            int size=q.size();
            
            while(size--) {
                vector<int> curr=q.front(); q.pop();
                
                for(auto d:dir) {
                    int x = d[0]+curr[0];
                    int y = d[1]+curr[1];
                    if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y]) 
                        continue;
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
            ans++;
        }
        return ans == 0 ? -1 : ans;
    }
};
