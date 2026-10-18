class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int n, int start,int sum, int target, vector<int>& candidates) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < n; i++) {
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtrack(n, i, sum, target, candidates);
                path.pop_back();
                sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        backtrack(n,0,0,target,candidates);
        return ans;
    }
};