class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int ans[2];
        int i;
        ans[0] = 1;
        ans[1] = 0;
        for (i = 3; i <= n; ++i) {
            ans[i % 2] += ans[(i - 1) % 2];
        }
        return ans[n % 2];
    }
};