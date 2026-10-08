class Solution {
   public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> all, closing;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            all.push(s[i]);
        }

        while (!all.empty()) {
            char x = all.top();
            if (x == ']' or x == '}' or x == ')') {
                closing.push(x);
                all.pop();
                continue;
            }
            if(closing.empty())return false;
            char y = closing.top();
            if ((x == '{' and y != '}') or (x == '[' and y != ']') or (x == '(' and y != ')')) {
                ans = false;
                break;
            } else {
                all.pop();
                closing.pop();
            }
        }
        if (ans == false or closing.size() > 0) return false;
        return true;
    }
};
