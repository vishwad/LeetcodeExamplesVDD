class Solution {
public:
    int compareVersion(string version1, string version2) {
        cout << "BEGIN CASE------------------------------" << endl;
        string::iterator iv1 = version1.begin(), iv2 = version2.begin();
        return chkContext(version1, iv1, version2, iv2);
    }

    int chkContext(string &v1, string::iterator &iv1, string &v2, string::iterator &iv2) {
        while (iv1 != v1.end() && *iv1 == '0') v1.erase(iv1);
        while (iv2 != v2.end() && *iv2 == '0') v2.erase(iv2);
        int sv1 = 0, sv2 = 0;
        cout << "condi: " << (iv1 == v1.end()) << endl;
        while (iv1 != v1.end() && *iv1 != '.') {
            cout << (*iv1 - 48) << endl;
            sv1 = sv1 * 10 + ((*iv1) - 48);
            ++iv1;
        }
        cout << "condi: " << (iv2 == v2.end()) << endl;
        while (iv2 != v2.end() && *iv2 != '.') {
            sv2 = sv2 * 10 + ((*iv2) - 48);
            ++iv2;
        }
        if (sv1 > sv2) return 1;
        else if (sv1 < sv2) return -1;
        else {
            if (iv1 == v1.end() && iv2 == v2.end()) return 0;
            return chkContext(v1, (iv1 = (iv1 == v1.end()) ? iv1 : iv1 + 1), v2, (iv2 = (iv2 == v2.end()) ? iv2 : iv2 + 1));
        }
    }
};