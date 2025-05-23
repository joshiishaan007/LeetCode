class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size(), left=0, right=0;
        int length = INT_MAX;
        vector<int> prefixSum(n,0);

        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        while(left<=right && right<n && left<n){
            if(prefixSum[right] >= target){
                while(prefixSum[right]-prefixSum[left] >= target){
                    left++;
                }

                length = min(length,right-left+1);
            }
            right++;
        }
        return length == INT_MAX ? 0 : length;
    }
};