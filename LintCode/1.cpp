class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        if (a < 0 && b >= 0) {
            a = -a;
            return b - a;
        }
        if (b < 0 && a >= 0) {
            b = -b;
            return a - b;
        }
        int tmp = 0, ans = 0, tmp1 = 1, op = 1;
        if (a < 0 && b < 0) {
            op = -1;
            a = -a;
            b = -b;
        }
        while (a != 0 || b != 0 || tmp != 0) {
            if ((a ^ b ^ tmp) & 1)
                ans |= tmp1;
            if ((a & 1 && b & 1) || (a & 1 && tmp & 1) || (b & 1 && tmp & 1))
                tmp = 1;
            else
                tmp = 0;
            a >>= 1;
            b >>= 1;
            tmp1 <<= 1;
        }
        return op * ans;
    }
};