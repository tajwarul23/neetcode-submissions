class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            //if the mid element is > right element min is on the right side
            //serach on the right side for minimum value
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            //else min element on the left side search on the left side for minimum value
            else {
                high = mid;
            }
        }
        //high == low will point the minimum value
        return nums[low];

    }
};
