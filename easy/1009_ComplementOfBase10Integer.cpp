class Solution {
public:
    int bitwiseComplement(int n) {
        int t = 0;
        if (n ==0) return 1;
        while (t < n) {
            t = (t << 1) + 1;
        }
        t = t ^ n;
        return t;
    }
};