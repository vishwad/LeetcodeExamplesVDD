class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (int i0 = 0; i0 < nums.size(); ++i0) {
            if (us.find(nums.at(i0)) == us.end()) us.insert(nums.at(i0));
            else return true;
        }
        return false;
    }
};