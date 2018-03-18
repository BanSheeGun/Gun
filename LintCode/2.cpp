typedef long long ll;
class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        ll ans = 0;
        while (n != 0) {
            ans += n / 5;
            n /= 5;
        } 
        return ans;
    }  
};