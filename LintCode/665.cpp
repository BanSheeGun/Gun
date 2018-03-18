class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        string ans = "";
        int c = 0;
        int la = num1.length();
        int lb = num2.length();
        int l = max(la, lb);
        for (int i = 1; i <= l; ++i) {
            int a = 0, b = 0;
            if (i <= la)
                a = num1[la - i] - '0';
            if (i <= lb)
                b = num2[lb - i] - '0';
            ans = " " + ans;
            ans[0] = (c + a + b) % 10 + '0';
            c = (c + a + b) / 10;
        }
        if (c != 0) {
            ans = " " + ans;
            ans[0] = c + '0';
        }
        return ans;
    }
};