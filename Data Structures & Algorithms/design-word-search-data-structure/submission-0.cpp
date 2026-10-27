class WordDictionary {
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    Node* root;

   public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) cur->children[i] = new Node();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(string word) {

        return dfs(word, 0, root);
    }

    bool dfs(const string& word, int j, Node* root) {
        Node* cur = root;

        for (int i = j; i < word.size(); i++) {
            if (word[i] == '.') {
                for (Node* child : cur->children) {
                    if (child != nullptr and dfs(word, i + 1, child))
                        return true;
                }
                return false;
            } else {
                if (cur->children[word[i] - 'a'] != nullptr)
                    cur = cur->children[word[i] - 'a'];
                else
                    return false;
            }
        }

        return cur->isEnd;
    }
};
