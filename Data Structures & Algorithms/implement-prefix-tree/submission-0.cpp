class PrefixTree {
    struct Node {
        Node* children[26];
        bool isEnd;
        Node() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };

    Node* root;

    Node* walk(string s) {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) return nullptr;
            cur = cur->children[i];
        }
        return cur;
    }

   public:
    PrefixTree() { root = new Node(); }

    void insert(string word) {
        Node* cur = root;
        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new Node();
            }
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        Node* cur = walk(word);
        return (cur != nullptr and cur->isEnd);
    }

    bool startsWith(string prefix) {
        Node* cur = walk(prefix);
        return cur != nullptr;
    }
};
