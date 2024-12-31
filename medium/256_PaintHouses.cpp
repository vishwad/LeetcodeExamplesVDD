class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int *s = new int[costs.size()*3]{0};
        return min({tc(0, 'r', s, costs), tc(0, 'g', s, costs), tc(0, 'b', s, costs)});
    }

    int tc(int i, char pc, int *&s, vector<vector<int>>& c) {
        if (i == c.size()-1) {
            switch(pc) {
                case 'r':
                    return c.at(i).at(0);
                case 'g':
                    return c.at(i).at(1);
                case 'b':
                    return c.at(i).at(2);
            }
        }
            switch(pc) {
                case 'r':
                return (s[i] = (s[i] == 0) ? (c.at(i).at(0) + min(tc(i+1, 'g', s, c), tc(i+1, 'b', s, c))) : s[i]);
                case 'g':
                if (s[i+c.size()] == 0) {
                    s[i+c.size()] = c.at(i).at(1) + min(tc(i+1, 'r', s, c), tc(i+1, 'b', s, c));
                }
                return s[i+c.size()];
                case 'b':
                if (s[i+2*c.size()] == 0) {
                    s[i+2*c.size()] = c.at(i).at(2) + min(tc(i+1, 'r', s, c), tc(i+1, 'g', s, c));
                }
                return s[i+2*c.size()];
            }
            
        return 0;
    }
};