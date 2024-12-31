class Solution {
public:
    void e(int bn, unordered_set<int> &c2z, unordered_map<int, unordered_set<int>> &cm, unordered_map<int, unordered_set<int>> &ac, deque<int> &p, int &mr) {
        if (cm.find(bn)->second.find(0) != cm.find(bn)->second.end()) c2z.insert(bn);
        unordered_set<int>::iterator s, is0 = cm.find(bn)->second.begin();
        while (is0 != cm.find(bn)->second.end()) {
            if (c2z.find(*is0) == c2z.end()) {
                ++mr;
                p.push_back(*is0);
                cm.emplace(*is0, (unordered_set<int>){});
                cm.find(*is0)->second.emplace(bn);
                s = is0;
                ++is0;
                cm.find(bn)->second.erase(s);
            } else ++is0;
        }

        is0 = ac.find(bn)->second.begin();
        while (is0 != ac.find(bn)->second.end()) {
            if (c2z.find(*is0) == c2z.end()) {
                p.push_back(*is0);
            }
            ++is0;
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int mr = 0;
        deque<int> p;
        unordered_map<int, unordered_set<int>> cm, ac;
        unordered_set<int> c2z;
        cm.emplace(0, (unordered_set<int>){});
        p.push_front(0);
        for (int i0 = 0; i0 < connections.size(); ++i0) {
            cm.emplace(connections.at(i0).at(0), (unordered_set<int>){});
            cm.find(connections.at(i0).at(0))->second.emplace(connections.at(i0).at(1));
            ac.emplace(connections.at(i0).at(0), (unordered_set<int>){});
            ac.find(connections.at(i0).at(0))->second.emplace(connections.at(i0).at(1));
            ac.emplace(connections.at(i0).at(1), (unordered_set<int>){});
            ac.find(connections.at(i0).at(1))->second.emplace(connections.at(i0).at(0));
            if (connections.at(i0).at(1) == 0) p.push_back(connections.at(i0).at(0));
        }
        while (p.size() > 0) {
            if (c2z.find(p.front()) == c2z.end()) {
                e(p.front(), c2z, cm, ac, p, mr);
                c2z.insert(p.front());
            }            
            p.pop_front();
        }
        return mr;
    }
};