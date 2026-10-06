class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> sequence;
        int         longest = 1;

        sort (nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
            cout << nums[i];
        cout << endl;
        
        if (nums.size() == 0)
            return 0;

        sequence.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue ;

            if (nums[i] - nums[i - 1] == 1)
                sequence.push_back(nums[i]);
            else
            {
                // longest = longest < sequence.size() ? sequence.size() : longest;
                sequence.clear();
                sequence.push_back(nums[i]);
            }
            longest = longest < sequence.size() ? sequence.size() : longest;
            // cout << longest;
        }
        cout << endl;
        for (int i = 0; i < sequence.size(); i++)
            cout << sequence[i];

        return longest;
    }
};
