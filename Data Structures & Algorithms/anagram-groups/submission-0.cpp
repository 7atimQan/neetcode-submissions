class Solution {
public:
    string getKey(string word)
    {
        sort(word.begin(), word.end());
        return word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        map<string, vector<string>> words;

        for (int i = 0; i < strs.size(); i++)
        {
            string key = getKey(strs[i]);
            words[key].push_back(strs[i]);
        }

        for (auto it = words.begin(); it != words.end(); it++)
        {
            group.push_back(it->second);
        }
        return group;
    }
};
