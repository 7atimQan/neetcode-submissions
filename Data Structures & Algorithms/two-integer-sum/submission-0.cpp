class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (s.find(complement) != s.end())
                return true;

            s.insert();
        }
        return false;
    }
};
