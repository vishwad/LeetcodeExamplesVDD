class Solution {
public:

    int rn (string &s, int &i) {
        int n = 0;
        while (i < s.length() && s.at(i) >= 48 && s.at(i) <= 57) {n = n * 10 + (int(s.at(i)) - 48);++i;}
        return n;
    }
    bool areNumbersAscending(string s) {
        int prev = INT_MIN;
        int num = 0;
        for (int i0 = 0; i0 < s.length(); ++i0) {
            if (s.at(i0) >= 48 && s.at(i0) <= 57) {
                num = rn(s, i0);
                if (num > prev) {prev = num;}
                else return false;
            }
        }
        return true;
    }
};