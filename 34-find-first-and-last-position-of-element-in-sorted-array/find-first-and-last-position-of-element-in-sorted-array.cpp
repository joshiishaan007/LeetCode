class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2,-1);

        if(nums.size() == 0) return ans;

        // for starting point
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                if(ans[0] == -1 || ans[0] > mid){
                    ans[0] = mid;
                }
                right = mid-1;
            } else if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target)
                left = mid+1;
        }

        // for ending point
        left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                if(ans[1] == -1 || ans[1] < mid){
                    ans[1] = mid;
                }
                left = mid+1;
            } else if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target)
                left = mid+1;
        }

        return ans;
        
    }
};