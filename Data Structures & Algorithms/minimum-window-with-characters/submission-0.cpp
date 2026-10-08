class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char,int>countT,window;
        for(char c : t)countT[c]++;

        int n = s.size(),l=0,have = 0, mn = INT_MAX, need = countT.size();
            pair<int,int>idx;

        for(int r = 0; r < n; r++){
            char c = s[r];
            window[c]++;
            if(countT[c] > 0 and countT[c] == window[c])have++;
            
            
            while(have == need) {
                if((r - l + 1) < mn){
                    mn = r - l + 1;
                    idx = {l, r};
                }

                window[s[l]]--;
                if(countT[s[l]] > 0 and countT[s[l]] > window[s[l]])have--;
                l++;
            }
        }
        if(mn == INT_MAX)return "";
        return s.substr(idx.first, mn);
    }
};