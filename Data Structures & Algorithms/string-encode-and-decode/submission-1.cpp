#include <sstream>

class Solution {
   public:
    string encode(vector<string>& strs) {
        unsigned long lengths = 0;
        for (int i = 0; i < strs.size(); i++) {
            lengths = (lengths * 10) + strs[i].size();
        }
        stringstream ss;
        ss << lengths;
        ss << "#";
        string encoded;
        ss >> encoded;
        for (int i = 0; i < strs.size(); i++) {
            encoded += strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        stringstream ss(s);

        string lengths, str;
        getline(ss, lengths, '#');
        getline(ss, str);

        string word = "";
        int j = 0;
        for (int i = 0; i < str.size() || j < lengths.size(); i++) {
            int length; 

            if (i == 0) {
                length = lengths[j] - '0';
            }

            length--;
            // if (i < str.size())
            //     word.push_back(str[i]);
            if (length == 0) 
            {
                strs.push_back(word);
                std::cout << "[hello" << word << "]" << std::endl;
                word = "";
                length = lengths[++j] - '0';
            }
        }

        return strs;
    }
};
