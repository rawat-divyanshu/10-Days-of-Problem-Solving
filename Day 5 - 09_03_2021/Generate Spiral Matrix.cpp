// Problem Link : https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int k) {
        vector<vector<int>> matrix;
        for(int i = 0; i < k; i++) {
            vector<int> rowVector(k,0);
            matrix.push_back(rowVector);
        }
        
        int m = k - 1;
        int n = k - 1;
        
        int r = 0, c = 0;
        int count = 1;

        while(r <= m && c <= n) {
            for(int i = c; i <= n; i++) {
               matrix[r][i] = count++;
            }
            r++;

            for(int i = r; i <= m; i++) {
                matrix[i][n] = count++;
            }
            n--;

            if(r <= m) {
                for(int i = n; i >= c; i--) {
                    matrix[m][i] = count++;
                }
                m--;
            }

            if(c <= n) {
                for(int i = m; i >= r; i--) {
                    matrix[i][c] = count++;
                }
                c++;
            }
        }
        return matrix;
    }
};