class Solution {
public:
    vector<string> c = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}; 
    string transform(string &w) {
        string a;
        for (int i1 = 0; i1 < w.length(); ++i1) {
            a = a + c.at(w.at(i1)-97);
        }
        return a;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> t;
        for (int i0 = 0; i0 < words.size(); ++i0) {t.emplace(transform(words.at(i0)));}
        return t.size();
    }
};