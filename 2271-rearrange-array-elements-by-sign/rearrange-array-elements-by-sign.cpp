class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> positiveNums;
        vector<int> negativeNums;

        for(int n : nums){
            if(n>=0)
                positiveNums.push_back(n);
            else
                negativeNums.push_back(n);
        }

        for(int i=0; i<positiveNums.size(); i++){
            nums[2*i] = positiveNums[i];
            nums[2*i+1] = negativeNums[i];
        }

        return nums;
    }
};