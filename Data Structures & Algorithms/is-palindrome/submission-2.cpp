class Solution {
public:
    string epurate(string& s)
    {
        string pure;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
                pure += toupper(s[i]);
        }
        return pure;
    }

    bool isPalindrome(string s) {
        string pure = epurate(s);
        cout << pure << endl;
        for (int i = 0; i < pure.size() / 2; i++)
        {
            int j = pure.size() - i - 1;
            if (pure[i] != pure[j])
            {
                cout << pure[j];
                return false;
            }
        }
        return true;
    }
};
