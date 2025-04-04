class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> result;
        int n = nums.size();
        int ans;

        for(int i=0; i<n; i++){
            result[nums[i]]++;

            if(result[nums[i]]>(n/2))
                ans=nums[i];
        }
        return ans;
    }
};