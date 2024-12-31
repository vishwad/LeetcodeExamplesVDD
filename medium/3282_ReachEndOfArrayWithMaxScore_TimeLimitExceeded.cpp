class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ms = 0;
        int *s = new int[nums.size()];
        for (int i0 = 0; i0 < nums.size()-1; ++i0) {s[i0] = -1;}
        s[nums.size()-1] = 0;
        ms = c(0, s, nums);
        return ms;
    }

    long long c(int i, int *&s, vector<int>& nums) {
        if (s[i] == -1) {
            long long m = LLONG_MIN;
            int k = i+1;
            while (k < nums.size()) {
                m = max(m, (long long)(k-i) * (long long)nums.at(i) +c(k, s, nums));
                ++k;
            }
            s[i] = m;
        }
        return s[i];
    }
};