class Solution {
public:
    int longestValidParentheses(string s) {
        int lp = 0, lvl = 0;
        array<int, 3> ret;
        ret = checkLvl(s, lp, 0, lvl);
        lp = (lp < 2 * ret.at(0)) ? (2 * ret.at(0)) : lp;
        return lp;
    }

    array<int, 3> checkLvl(string &s, int &lp, int si, int &lvl) {
        int cv = 0;
        bool open = false;
        array<int, 3> ret;
        while (si < s.length()) {
            if (s.at(si) == '(') {
                if (!open) open = true;
                else {
                    ret = checkLvl(s, lp, si, ++lvl);
                    //cout << "Got: " << ret.at(0) << ' ' << ret.at(1)<< ' ' << ret.at(2) << endl;
                    cv = cv + ((ret.at(2) || (ret.at(1) >= s.length() && open)) ? 0 : ret.at(0));
                    //cout << "cvadjust : " << cv << endl;
                    si = ret.at(1)-1;
                    --lvl;
                }
                
            }
            else if (s.at(si) == ')') {
                if (open) {
                    ++cv;
                    open = false;
                } else if (lvl == 0) {
                    //cout << "preadjustzl cv: " << cv << endl;
                    lp = (lp < 2*cv) ? 2*cv : lp;
                    cv = 0;
                }
                else {
                    //cout << "preadjustbi cv: " << cv << endl;
                    lp = (lp < 2*cv) ? 2*cv : lp;
                    return {cv, si, open};
                }
                
            }
            ++si;
        }
        //cout << "returned: " << lvl << " " << open << endl;
        //cout << "preadjust cv: " << cv << endl;
        lp = (lp < 2*cv) ? 2*cv : lp;
        return {cv, si, open};
    }
};