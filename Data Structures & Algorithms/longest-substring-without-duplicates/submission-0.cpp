class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), left = 0, mx = 0;
        set<char>st;
        for(int right = 0; right < n; right++){
            //if duplicate found shrink the window from the left
            while(st.find(s[right]) != st.end()){
                    st.erase(s[left]);
                    left++;
            }
            //append the character to right and compute mx
            st.insert(s[right]);
            mx = max(mx, right - left + 1);
        }

        return mx;
    }
};
