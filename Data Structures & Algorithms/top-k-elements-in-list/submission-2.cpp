class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++)
            frequency[nums[i]]++;

        map<int, vector<int>> freqToNumbers;

        for (auto it = frequency.begin(); it != frequency.end(); it++)
            freqToNumbers[it->second].push_back(it->first);

        vector<int> topFrequent;

        for (auto it = freqToNumbers.rbegin();
             it != freqToNumbers.rend() && k > 0;
             it++)
        {
            for (int i = 0; i < it->second.size() && k > 0; i++)
            {
                topFrequent.push_back(it->second[i]);
                k--;
            }
        }

        return topFrequent;
    }
};