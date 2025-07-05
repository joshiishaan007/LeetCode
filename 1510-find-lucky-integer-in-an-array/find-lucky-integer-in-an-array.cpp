class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int,int> freq;
        int ans = -1;

        for(int num: arr){
            freq[num]++;
        }

        for(auto [a,b]: freq){
            if(a == b)
                ans = max(ans, a);
        }

        return ans;
    }
};