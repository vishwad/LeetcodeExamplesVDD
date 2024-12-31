class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> c;
        vector<int> a;
        int cnt = floor(nums.size()/3) + 1;
        for (int i0 = 0; i0 < nums.size(); ++i0) {
            if (c.find(nums.at(i0)) == c.end()) {
                c.insert({nums.at(i0), 1});
            } else {
                ++c.find(nums.at(i0))->second;
                
            }
            if (c.find(nums.at(i0))->second == cnt) {
                    a.push_back(nums.at(i0));
                } 
        }
        return a;
    }
};