class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> temp1, temp2;
        int n = nums.size();

        if(n==1) return nums[0];
        
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        int ans1 = findMax(temp1);
        int ans2 = findMax(temp2);

        return max(ans1,ans2);
    }

    int findMax(vector<int>& nums){
        int n = nums.size(), x;
        vector<int> dp(n,0);

        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            i-2 < 0? x=0: x=dp[i-2];

            int pick = nums[i] + x;
            int notPick = dp[i-1];
            
            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }
};