class Solution {
public:
    int findMin(vector<int>& nums) {
        return mf(nums, 0, nums.size()-1);
    }

    int mf(vector<int> &n, int s, int e) {
        if (s == e) return n.at(s);
        else if (s == e - 1) return min(n.at(s), n.at(e));
        else if (n.at(s) < n.at(e)) return n.at(s);
        int m = (s + e) / 2;
        if (n.at(m) > n.at(e)) return mf(n, m, e);
        else if (n.at(m) < n.at(e)) return mf(n, s, m);
        return min(mf(n, s, m), mf(n, m+1, e));
    }
};