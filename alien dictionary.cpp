
class Solution {
  public:
    string topoSort(vector<vector<int> >& adj, int present, int *inDegree)
    {
        string topo = "";
        
        queue<int> q;
        
        for (int i = 0; i < 26; i++)
        {
            if (present & (1 << i) && inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u])
            {
                inDegree[v]--;
                
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
            
            topo.push_back((char)(u + 'a'));
            present = present & ~(1 << u);
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (present & (1 << i))
            {
                if (inDegree[i]) {
                    return "";
                }
                
                topo.push_back((char)(i + 'a'));
            }
        }
        
        return topo;
    }
  
    string findOrder(vector<string> &words) {
        // code here
        int present = 0;
        int w = words.size();
        
        string s1 = "", s2 = "";
        int len = 0;
        bool flag = false;
        
        vector<vector<int> > adj(26);
        int inDegree[26] = {0};
        
        for (int i = 0; i < w - 1; i++)
        {
            s1 = words[i];
            s2 = words[i + 1];
            
            len = min(s1.size(), s2.size());
            flag = false;
            
            for (int p = 0; p < s1.size() || p < s2.size(); p++)
            {
                if (p < len && !flag)
                {
                    if (s1[p] != s2[p])
                    {
                        adj[s1[p] - 'a'].push_back(s2[p] - 'a');
                        inDegree[s2[p] - 'a']++;
                        flag = true;
                    }
                }
                
                if (p < s1.size()) {
                    present |= (1 << (s1[p] - 'a'));
                }
                
                if (p < s2.size()) {
                    present |= (1 << (s2[p] - 'a'));
                }
            }
            
            if (flag == false && s1.size() > s2.size()) {
                return "";
            }
        }
        
        if (words.size() == 1)
        {
            for (char x : words[0])
            {
                present |= (1 << x - 'a');
            }
        }
        
        string ans = topoSort(adj, present, inDegree);
        return ans;
    }
};
