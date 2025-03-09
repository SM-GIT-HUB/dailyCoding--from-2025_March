class Solution {
public:
    void dfs(string &b, string word, vector<string>& output, vector<vector<string> >& ans, unordered_map<string, int>& mapp)
    {
        if (word == b)
        {
            ans.push_back(output);
            reverse(ans.back().begin(), ans.back().end());
            return;
        }

        int len = word.size();
        int lvl = mapp[word];
                
        for (int i = 0; i < len; i++)
        {
            char org = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (mapp.count(word) && mapp[word] == lvl - 1)
                {
                    output.push_back(word);
                    dfs(b, word, output, ans, mapp);
                    output.pop_back();
                }
            }

            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        unordered_map<string, int> mapp;
        
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
        
        vector<vector<string> > ans;

        queue<string> q;
        q.push(beginWord);
        words.erase(beginWord);
        int len = beginWord.size();

        mapp[beginWord] = 1;
        bool flag = 0;
        
        while (!q.empty() && !flag)
        {
            int size = q.size();

            while (!flag && size--)
            {
                string word = q.front();
                q.pop();

                int lvl = mapp[word];
                
                for (int i = 0; i < len; i++)
                {
                    char org = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;

                        if (words.count(word))
                        {
                            mapp[word] = lvl + 1;

                            if (word == endWord)
                            {
                                flag = 1;
                                break;
                            }

                            words.erase(word);
                            q.push(word);
                        }
                    }

                    word[i] = org;
                }
            }
        }

        if (flag)
        {
            vector<string> output = {endWord};
            dfs(beginWord, endWord, output, ans, mapp);
        }

        return ans;
    }
};
