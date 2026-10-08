class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<long long>LR(n), RL(n);

        LR[0] = nums[0], RL[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            LR[i] = LR[i-1] * nums[i];
        }

        for(int i = n-2; i>=0; i--){
            RL[i] = RL[i+1] * nums[i];
        }
        vector<int>ans(n);
        ans[0] = RL[1], ans[n-1] = LR[n-2];
        for(int i=1; i<n-1; i++){
            ans[i] = RL[i+1] * LR[i-1];
        }
        return ans;
    }
};