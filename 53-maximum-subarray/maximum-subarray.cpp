class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max=nums[0], sum=0;

        for(int n : nums){
            sum += n;

            if(sum > max)
                max = sum;
            
            if(sum < 0)
                sum = 0;
        }

        return max;
    }
};