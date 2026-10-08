class Solution {
    bool isChar(char c) {
        return ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z'));
    }
    bool isNumber(char c) { return (c >= '0' and c <= '9'); }
    bool nonAlphaNumeric(char c) {
        if (!isChar(c) and !isNumber(c))
            return true;
        else
            return false;
    }

public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;

        while (l <= r) {
            if (nonAlphaNumeric(s[l])) {
                l++;
                continue;
            }
            if (nonAlphaNumeric(s[r])) {
                r--;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};