
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000;
        int visited[100001] = {0};
        
        queue<int> q;
        
        q.push(start);
        int level = 0;
        
        while (!q.empty())
        {
            int size = q.size();
            
            while (size--)
            {
                int top = q.front();
                q.pop();
                
                if (top == end) {
                    return level;
                }
                
                for (int x : arr)
                {
                    if (!visited[(top * x) % mod])
                    {
                        visited[(top * x) % mod] = true;
                        q.push((top * x) % mod);
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};
