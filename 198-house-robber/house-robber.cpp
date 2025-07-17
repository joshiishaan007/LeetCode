class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size(), x, maxProfit;
        vector<int> dp(n,0);

        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            i-2 < 0? x=0: x=dp[i-2];

            int pick = nums[i] + x;
            int notPick = dp[i-1];

            maxProfit = max(pick, notPick);
            dp[i] = maxProfit;
        }

        return dp[n-1];
    }
};