class Solution {
public:
    int preimageSizeFZF(int k) {
        int c = 0;
        int sv = 0, cc = 0;
        unordered_map<unsigned int, unsigned int> r;
        unsigned int ds=0;
        int n5 = 0;
        r.insert({5, 1});
        while (cc < k) {
            sv = sv + 5;
            if (sv & 1) {
                ++cc;
                ds = sv / 5;
                if (r.find(ds) != r.end()) {
                    r.insert({sv, 1 + r.find(ds)->second});
                    cc = cc + r.find(ds)->second;
                } else {
                    n5 = 0;
                    while (ds % 5 == 0) {
                        ++n5;
                        ds = ds / 5;
                    }
                    r.insert({sv, 1 + n5});
                }
            } else {
                ++cc;
                ds = (sv >> 1) / 5;
                if (r.find(ds) != r.end()) {
                    r.insert({sv, 1 + r.find(ds)->second});
                    cc = cc + r.find(ds)->second;
                } else {
                    n5 = 0;
                    while (ds % 5 == 0) {
                        ++n5;
                        ds = ds / 5;
                    }
                    r.insert({sv, 1 + n5});
                }
            }
        }
        if (cc > k) return 0;
        return 5;
    }
};