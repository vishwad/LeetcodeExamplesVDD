class Solution {
public:
    int minTimeToType(string word) {
        int mt = 0, p = 0;
        for (int i0 = 0; i0 < word.size(); ++i0) {
            mt = mt + min(max(p, word.at(i0) - 97) - min(p, word.at(i0) - 97), min(p, word.at(i0) - 97) + 26 - max(p, word.at(i0) - 97)) + 1;
            p = word.at(i0)-97;
        }
        return mt;
    }
};