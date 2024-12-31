class Solution {
public:
    bool rotateString(string s, string goal) {
        bool r = false;
        if (s.length() != goal.length()) return false;
        for (int i0 = 0; i0 < goal.size(); ++i0) {
            r = max(r, r || (s == goal));
            s.push_back(s.front());
            s.erase(s.begin());
        }
        return r;
    }
};