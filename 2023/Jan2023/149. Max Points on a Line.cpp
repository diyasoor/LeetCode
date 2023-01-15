Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
  
Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 
Constraints:
1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
  
class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        // (xi, yi)        (xk, yk)       (xj, yj)
        //    *----------------*--------------*
        // (yj - yi)   (yk - yi)
        // --------- = --------- 
        // (xj - xi)   (xk - xi)
        
        // => (yj - yi)*(xk - xi) = (yk - yi)*(xj - xi)
        // then we can say that they are on same straight line 
        int n=p.size();
        if(n<=2) return n;
        int maxPoints = 2;  // always there are two points to make a line
  
        // make straight line using every 2 points and then find 
        // how many of the points lie on it.
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int cnt=2;  // always there are two points to make a line
                for(int k=0;k<n;k++) {
                    if(k!=i && k!=j) {
                        int a=(p[j][1]-p[i][1])*(p[k][0]-p[i][0]);
                        int b=(p[k][1]-p[i][1])*(p[j][0]-p[i][0]);
                        if(a==b) cnt++;
                    }
                }
                maxPoints = max(maxPoints, cnt);
            }
        }
        return maxPoints;
    }
};
