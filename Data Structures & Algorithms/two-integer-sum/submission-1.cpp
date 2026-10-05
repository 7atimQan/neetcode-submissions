class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;

        int i = 0;
        int complement;
        for (; i < nums.size(); i++)
        {
            complement = target - nums[i];

            if (s.find(complement) != s.end())
                break ;

            s[nums[i]] = i;
        }
        vector<int> result = {s[complement], i};
        return result;
    }
};
