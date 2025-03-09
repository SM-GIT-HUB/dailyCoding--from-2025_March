class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        
        for (string &w : wordList)
        {
            words.insert(w);
        }
        
        if (words.count(endWord) == 0) {
            return {};
        }
        else if (beginWord == endWord) {
            return {{beginWord}};
        }
        
        words.erase(beginWord);
        int len = beginWord.size();
        
        vector<vector<string> > ans;
        
        queue<vector<string> > q;
        q.push({beginWord});
        
        vector<string> used;
        used.push_back(beginWord);
        
        bool flag = 0;
        
        while (!q.empty())
        {
            int size = q.size();
            
            while (size--)
            {
                vector<string> curr = q.front();
                q.pop();
                
                string word = curr.back();
                
                for (int i = 0; i < len; i++)
                {
                    string temp = word;
                    
                    for (char x = 'a'; x <= 'z'; x++)
                    {
                        temp[i] = x;
                        
                        if (temp == endWord)
                        {
                            flag = true;
                            curr.push_back(temp);
                            
                            ans.push_back(curr);
                            break;
                        }
                        else if (words.count(temp))
                        {
                            curr.push_back(temp);
                            q.push(curr);
                            used.push_back(temp);
                            
                            curr.pop_back();
                        }
                    }
                }
            }
            
            if (flag) {
                break;
            }
            
            while (!used.empty())
            {
                words.erase(used.back());
                used.pop_back();
            }
        }
        
        return ans;
    }
};
