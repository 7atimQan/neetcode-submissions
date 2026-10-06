class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++)
            frequency[nums[i]]++;

        map<int, int> revFreq;
        for (auto it = frequency.begin(); it != frequency.end(); it++)
        {
            revFreq[it->second] = it->first;
        }

        vector<int> topFrequent;
        for (auto it = revFreq.rbegin(); it != revFreq.rend() && k > 0 ; it++)
        {
            topFrequent.push_back(it->second);
            k--;
        }
        return topFrequent;
    }
};
