class Solution {
public:
    int bs (int left, int right, int target, vector<int>&nums) {

            while(left <= right){
                int mid = left + (right - left) / 2;
                if(nums[mid] == target)return mid;

                if(nums[mid] > target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0, r = n - 1;
        
        //find pivot point first
        while(l < r ){
            int mid = l + (r - l) /2;
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        int partionPoint = l;
        int res1 = bs(0, partionPoint-1, target, nums);
        int res2 = bs(partionPoint, n-1, target, nums);
        return max(res1, res2);
    }
};
