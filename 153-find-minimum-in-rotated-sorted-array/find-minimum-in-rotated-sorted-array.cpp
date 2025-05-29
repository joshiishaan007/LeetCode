class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int min = INT_MAX, left = 0, right = nums.size()-1;

        while(left <= right){

            int mid = (left+right)/2;

            if(nums[mid] < min){
                min = nums[mid];
            }

            else if(nums[mid] <= nums[right]){
                right = mid-1;
            }

            else{
                left = mid+1;
            }
        }

        return min;
    }
};