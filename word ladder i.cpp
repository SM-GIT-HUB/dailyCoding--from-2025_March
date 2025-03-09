class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> words;
        
        for (string &w : wordList)
        {
            words.insert(w);
        }
        
        if (words.count(targetWord) == 0) {
            return 0;
        }

        
        int ans = 1;
        
        queue<string> q;
        q.push(startWord);
        words.erase(startWord);

        int size = 0;
        string temp = "";
        
        while (!q.empty())
        {
            size = q.size();
            
            while (size--)
            {
                string real = q.front();
                q.pop();
                                
                for (int i = 0; i < real.size(); i++)
                {
                    temp = real;
                    
                    for (char x = 'a'; x <= 'z'; x++)
                    {
                        temp[i] = x;
                        
                        if (words.erase(temp))
                        {
                            if (temp == targetWord) {
                                return (ans + 1);
                            }
                            
                            q.push(temp);
                        }
                    }                    
                }
            }
            
            ans++;
        }
        
        return 0;
    }
};
