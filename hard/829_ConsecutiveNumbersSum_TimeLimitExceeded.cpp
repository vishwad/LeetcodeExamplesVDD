class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int c = 0, s = 0, l = 0;
        int ll = 0, ul = 0, ps = 0;
        for (int i0 = 1; i0 <= n; ++i0) {
            l = n / i0 + 1;
            ll = 1;
            ul = ll + (i0-1);
            if (((ul) * (ul + 1)) / 2 > n) break;
            s = ps + ul;
            ps = s;
            while (s <= n) {
                c = c + (s == n);
                s = s - ll;
                ++ll;
                ++ul;
                s = s + ul;
            }
        }
        return c;
    }
};