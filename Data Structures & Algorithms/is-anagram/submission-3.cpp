class Solution {
public:
    int countChar(const string& s, const char c)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                count++;
        }
        return count;
    }

    bool isAnagram(const string& s, const string t) {
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            int sCount = countChar(s, s[i]);
            int tCount = countChar(t, s[i]);
            if (tCount != sCount)
                return false;
        } 
        return true;
    }
};
