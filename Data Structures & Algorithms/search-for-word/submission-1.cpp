class Solution {
   public:
    int maxRow, maxCol;
    string path, ans;
    vector<vector<bool>> vis;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    bool valid(int row, int col) {
        if (row >= 0 and row < maxRow and col >= 0 and col < maxCol)
            return true;
        else
            return false;
    }

    void backtrack(vector<vector<char>>& board, string word, int row, int col) {
        if (path == word) {
            ans = path;
            return;
        }
        if ((path.size() == word.size()) and (word != path)) {
            return;
        }
        if (path.size() > word.size()) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (valid(newRow, newCol) and !vis[newRow][newCol] and
                board[newRow][newCol] == word[path.size()]) {
                vis[newRow][newCol] = true;
                path.push_back(board[newRow][newCol]);
                backtrack(board, word, newRow, newCol);
                path.pop_back();
                vis[newRow][newCol] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        maxRow = board.size();
        maxCol = board[0].size();
        bool found = false;
        vis.assign(maxRow, vector<bool>(maxCol, false));
        for (int i = 0; i < maxRow; i++) {
            for (int j = 0; j < maxCol; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = true;
                    path.push_back(board[i][j]);
                    backtrack(board, word, i, j);
                    
                    path.clear();
                    vis[i][j] = false;
                }
                if (ans == word) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        return found;
    }
};
