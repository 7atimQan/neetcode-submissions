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
        string num, str, word = "";
        int    n = 0;
        vector<int> lengths;

        getline(ss, num, '#');
        int number = stringToInt(num);
        for (int i = 0; i < number; i++)
        {
            getline(ss, num, '#');
            lengths.push_back(stringToInt(num));
        }
        getline(ss, str);
        for (int i = 0; i < str.size(); i++)
        {
            if (lengths[n] == 0){
                strs.push_back("");
                continue ;
            }
            if (str[i] == '#')
            {
                if (word.size() == lengths[n])
                {
                    strs.push_back(word);
                    word = "";
                    n++;
                }
                else
                    word += str[i];
            }
            else
                word += str[i];
        }
        return strs;
    }
};
