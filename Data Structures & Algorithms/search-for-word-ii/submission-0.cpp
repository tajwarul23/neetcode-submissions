class Solution {
    struct Node {
        Node* children[26];
        bool isEnd;
        Node() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };
    Node* root;
    void insert(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) cur->children[i] = new Node();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    string path;
    vector<string> ans;
    bool vis[13][13];
    int r, c;
    bool valid(int i, int j) {
        if (i >= 0 and j >= 0 and i < r and j < c and !vis[i][j])
            return true;
        else
            return false;
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int i, int j, Node* node, vector<vector<char>>& board) {
        Node* next = node->children[board[i][j] - 'a'];
        if (next == nullptr) return;
        path += board[i][j];
        if (next->isEnd == true) {
            ans.push_back(path);
            next->isEnd = false;
        }
        vis[i][j] = true;
        for (int a = 0; a < 4; a++) {
            int nr = i + dx[a], nc = j + dy[a];
            if (valid(nr, nc)) {
                dfs(nr, nc, next, board);
            }
        }
        vis[i][j] = false;
        path.pop_back();
    }

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        r = board.size();
        c = board[0].size();
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                vis[i][j] = false;
            }
        }
        for (string word : words) insert(word);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dfs(i, j, root, board);
            }
        }
        return ans;
    }
};