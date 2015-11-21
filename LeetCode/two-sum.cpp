class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        int i, j;

        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
            }
        }

        result.push_back(0);
        result.push_back(0);
        return result;
    }
};