class Solution {
public:
    /*
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        if (nums.size()== 0)
            return -1;
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l != r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
};