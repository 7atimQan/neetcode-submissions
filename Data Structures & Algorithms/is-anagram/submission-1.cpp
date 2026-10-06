#include <stdlib.h>

class Solution {
public:
    int countChar(string s, char c)
    {
        int count = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == c)
                count++;
        }
        return count;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        for (int i = 0; s[i] != '\0'; i++)
        {
            int sCount = countChar(s, s[i]);
            int tCount = countChar(t, s[i]);
            if (tCount != sCount)
                return false;
        } 
        return true;
    }
};
