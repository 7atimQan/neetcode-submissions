class Solution {
public:
    bool    isOpen(char c)
    {
        return (c == '(' || c == '{' || c == '[');
    }

    bool isValid(string s) {
        stack<char> cont;

        for (int i = 0; i < s.size(); i++)
        {
            if (isOpen(s[i]))
                cont.push(s[i]);
            else if (s[i] == ')' && !cont.empty() && cont.top() == '(')
                cont.pop();
            else if (s[i] == '}' && !cont.empty() && cont.top() == '{')
                cont.pop();
            else if (s[i] == ']' && !cont.empty() && cont.top() == '[')
                cont.pop();
            else
                return false;
        }
        if (!cont.empty())
            return false;
        return true;
    }
};
