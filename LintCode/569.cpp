class Solution {
public:
    /*
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num) {
        // write your code here
        int ans = 0;
        while (num != 0) {
            ans += num % 10;
            num /= 10;
        }
        if (ans > 9)
            return addDigits(ans);
        else
            return ans;
    }
};