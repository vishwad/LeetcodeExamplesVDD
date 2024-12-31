class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ms = 0;
        unordered_map<int, unordered_map<int, int>> r;
        dp(r, cardPoints, k, 0, 0, cardPoints.size());
        return (r.find(0)->second).find(cardPoints.size())->second;
    }

    int dp(unordered_map<int, unordered_map<int, int>>& r, vector<int>& cp, int &k, int c, int i, int l) {
        if (c == k || l == 0) return 0;
        else if (r.find(i) != r.end() && (r.find(i)->second).find(l) != (r.find(i)->second).end()) return (r.find(i)->second).find(l)->second;
        int cm = max(cp.at(i) + dp(r, cp, k, c+1, i+1, l-1), cp.at(i+l-1) + dp(r, cp, k, c+1, i, l-1));
        if (r.find(i) == r.end()) r.insert({i, {}});
        (r.find(i)->second).insert({l, cm});
        return cm;
    }
};