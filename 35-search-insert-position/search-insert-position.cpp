class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }

    int binarySearch(vector<int> nums, int left, int right, int key){

        while(left <= right){

            int mid = (left+right)/2;

            if(nums[mid] == key)
                return mid;

            else if(nums[mid] > key)
                right = mid-1;

            else if(nums[mid] < key)
                left = mid+1;
        }

        return left;
    }
};