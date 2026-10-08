class Solution {
public:

    string encode(vector<string>& strs) {
            string res;
            int n = strs.size();
            for(int i=0; i<n; i++){
                res += strs[i];
                res+=";";
            }
            
            return res;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int n = s.size();

        int i = 0;
        while(i < n){
            string cur = "";
            int j = i;
            while(s[j] != ';'){
                cur+=s[j];
                j++;
            }
            res.push_back(cur);
            i = j + 1;
        }
        return res;
    }
};
