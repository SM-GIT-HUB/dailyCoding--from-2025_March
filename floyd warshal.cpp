
// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        
        for (int k = 0; k < n; k++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (mat[u][k] != -1 && mat[k][v] != -1) {
                        mat[u][v] = (mat[u][v] == -1)? mat[u][k] + mat[k][v] : min(mat[u][v], mat[u][k] + mat[k][v]);
                    }
                }
            }
        }
    }
};
