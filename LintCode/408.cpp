class Solution {
public:
    /*
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        string ans = "";
        int la = a.length();
        int lb = b.length();
        int l = max(la, lb);
        int na, nb, nc = 0;
        for (int i = 1; i <= l; ++i) {
            if (la >= i && a[la - i] == '1')
                na = 1;
            else
                na = 0;
            if (lb >= i && b[lb - i] == '1')
                nb = 1;
            else
                nb = 0;
            if (na ^ nb ^ nc == 1)
                ans = "1" + ans;
            else
                ans = "0" + ans;
            if (na + nb + nc >= 2)
                nc = 1;
            else
                nc = 0;
        }
        if (nc != 0)
            ans = "1" + ans;
        return ans;
    }
};