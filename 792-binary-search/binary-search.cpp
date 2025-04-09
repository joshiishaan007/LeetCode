class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }

    int bs(vector<int> nums, int l, int r, int key){

        if (l > r) return -1;  // base case: key not found

    int mid = (l + r) / 2;

    if (nums[mid] == key)
        return mid;
    else if (nums[mid] > key)
        return bs(nums, l, mid - 1, key);
    else
        return bs(nums, mid + 1, r, key);
    }
};