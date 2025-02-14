class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> hashmap;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];

            // check if current value is there or not in hashmap
            if(hashmap.find(nums[i]) != hashmap.end()){
                ans.push_back(hashmap[nums[i]]);
                ans.push_back(i);
            }else{
                hashmap[rem] = i;
            }
        }
        return ans;

    }
};