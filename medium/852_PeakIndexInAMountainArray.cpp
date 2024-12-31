class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int r0 = jumpin(arr, 0, (arr.size()-1)/2);
        return (r0 == -1) ? jumpin(arr, (arr.size()-1)/2+1, (arr.size()-1)) : r0;
    }

    int jumpin(vector<int>& arr, int s, int e) {
        if (s == e) {
            if (!(s == 0 || s == arr.size()-1)) {
                if (arr.at(s) > arr.at(s-1) && arr.at(s) > arr.at(s+1)) return s;
            }
            return -1;
        }
        if (!(s == 0)) {
            if (arr.at(s) > arr.at(s-1) && arr.at(s) > arr.at(s+1)) return s;
        }
        if (!(e == arr.size()-1)) {
            if (arr.at(e) > arr.at(e-1) && arr.at(e) > arr.at(e+1)) return e;
        }
        int r0 = jumpin(arr, s, (s+e)/2);
        return (r0 == -1) ? jumpin(arr, (s+e)/2+1, e) : r0;
    }
};