class Solution {
public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double ans = 1;
        double tmp = x;
        while (n != 0) {
            if (n & 1)
                ans *= tmp;
            tmp = tmp * tmp;
            n /= 2;
        }
        return ans;
    }
};