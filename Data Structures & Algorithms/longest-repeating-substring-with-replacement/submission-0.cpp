class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        set<char>st(s.begin(), s.end());
        int mx = 0;
        for(char c : st) {
            int count = 0, l = 0;
            for(int r = 0; r<n; r++){
                if(s[r] == c)count++;

                while((r - l + 1) - count > k){
                    if(s[l] == c)count--;
                    l++;
                }
                mx = max(mx, (r-l+1));
            }
        }
        return mx;
    }
};
