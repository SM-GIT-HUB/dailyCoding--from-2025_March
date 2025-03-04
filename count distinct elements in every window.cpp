class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int, int> mapp;
        
        vector<int> ans;
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < k; i++)
        {
            mapp[arr[i]]++;
            
            if (mapp[arr[i]] == 1) {
                count++;
            }
        }
        
        ans.push_back(count);
        
        for (int i = 1; i + k - 1 < n; i++)
        {
            mapp[arr[i - 1]]--;
            
            if (mapp[arr[i - 1]] == 0) {
                count--;
            }
            
            mapp[arr[i + k - 1]]++;
            
            if (mapp[arr[i + k - 1]] == 1) {
                count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};
