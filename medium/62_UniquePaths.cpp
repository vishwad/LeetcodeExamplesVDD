class Solution {
public:
    int uniquePaths(int m, int n) {
        int **w = new int*[m];
        for (int i0 = 0; i0 < m; ++i0) {
            w[i0] = new int[n]{0};
        }
        return findup(0,0,w,m,n);
    }

    int findup(int r, int c, int **&w, int &m, int &n) {
        if (r == m - 1 && c == n - 1) return 1;
        if (w[r][c] == 0) {
        w[r][c] = ((r < m - 1) ? findup(r+1, c, w, m, n) : 0)
        + ((c < n - 1) ? findup(r, c+1, w, m, n) : 0);}
        return w[r][c];

    }
};