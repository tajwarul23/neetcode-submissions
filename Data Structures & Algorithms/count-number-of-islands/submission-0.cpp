class Solution {
   public:
    int row, col;
    bool isValid(int i, int j) {
        if (i >= 0 and j >= 0 and i < row and j < col) return true;
        return false;
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';

        for (int a = 0; a < 4; a++) {
            int ni = i + dx[a];
            int nj = j + dy[a];
            if (isValid(ni, nj) and grid[ni][nj] == '1') {
                dfs(ni, nj, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};
