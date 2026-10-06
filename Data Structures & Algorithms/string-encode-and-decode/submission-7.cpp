#include <sstream>

class Solution {
   public:
    string sizeToString(size_t n)
    {
        stringstream ss;
        ss << n;
        return ss.str();
    }

    int stringToInt(string s)
    {
        stringstream ss(s);
        int n; 
        ss >> n;
        return n;
    }
    string encode(vector<string>& strs) {
        string encoded = sizeToString(strs.size()) + "#";

        for (int i = 0; i < strs.size(); i++)
            encoded += sizeToString(strs[i].size()) + "#";
        for (int i = 0; i < strs.size(); i++)
            encoded += strs[i] + "#";
        std::cout << encoded;
        return encoded;
    }
    // string encode(vector<string>& strs) {
    //     unsigned long lengths = 0;
    //     for (int i = 0; i < strs.size(); i++) {
    //         lengths = (lengths * 10) + strs[i].size();
    //     }
    //     stringstream ss;
    //     ss << strs.size();
    //     ss << "#";
    //     ss << lengths;
    //     ss << "#";
    //     string encoded;
    //     ss >> encoded;
    //     for (int i = 0; i < strs.size(); i++) {
    //         encoded += strs[i];
    //     }
    //     return encoded;
    // }

    // vector<string> drecode(string s) {
    //     vector<string> strs;
    //     stringstream ss(s);

    //     string lengths, str, num;
    //     getline(ss, num, '#');
    //     getline(ss, lengths, '#');
    //     getline(ss, str);

    //     stringstream ss2(num);
    //     int nums;
    //     ss2 >> nums;
    //     string word = "";
    //     if (str.empty())
    //     {
    //         for (int i = 0; i < nums - '0'; i++)
    //         {
    //             strs.push_back("");
    //         }
    //     }
    //     for (int i = 0; i < str.size(); i++) {
    //         int j;
    //         int length;

    //         if (i == 0) {
    //             j = 0;
    //             length = lengths[j] - '0';
    //         }

    //         length--;
    //         word.push_back(str[i]);
    //         if (length == 0) 
    //         {
    //             strs.push_back(word);
    //             word = "";
    //             length = lengths[++j] - '0';
    //         }
    //     }

    //     return strs;
    // }

    vector<string> decode(string s) {
        vector<string> strs;
        stringstream ss(s);
        string num, word;
        vector<int> lengths;

        getline(ss, num, '#');
        int number = stringToInt(num);
        for (int i = 0; i < number; i++)
        {
            getline(ss, num, '#');
            lengths.push_back(stringToInt(num));
        }
        for (int i = 0; i < number; i++)
        {
            getline(ss, word, '#');
            if (word.size() == lengths[i])
                strs.push_back(word);
            else
                i--;
        }
        return strs;
    }
};
