class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int l = 0, il = 0;
        array<char, 5> v = {'a', 'e', 'i', 'o', 'u'};
        int c = 0;
        string::iterator is0 = word.begin();
        while (is0 != word.end()) {
            if (*is0 == v.at(c)) ++il;
            else if (c != 4 && il > 0 && *is0 == v.at(c+1)) {
                ++il;
                ++c;
            }
            else {
                if (c == 4) l = (il > l) ? il : l;
                c = 0;
                il = 0;
                if (*is0 == 'a') ++il;
                //cout << c << " " << il;
            }
            ++is0;
        }
        if (c == 4) l = (il > l) ? il : l;
        return l;
    }
};