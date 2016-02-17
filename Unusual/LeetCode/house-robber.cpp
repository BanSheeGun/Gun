class Solution {
public:
    int rob(vector<int>& nums) {
        int result, i, j;
        int rob[10000];
        int notrob[10000];
        int n = nums.size();

        memset(rob , 0 , sizeof(rob));
        memset(notrob , 0 , sizeof(notrob));
        if (n != 0)
            rob[0]=nums[0];

        for (i = 1; i < n; ++i) {
            rob[i] = notrob[i-1] + nums[i];
            notrob[i] = max(notrob[i-1] , rob[i-1]);
        }
        if (n != 0)
            result = max(rob[n-1] , notrob[n-1]);
        return result;
    }
};