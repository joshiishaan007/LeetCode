class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> freq;
        string ans = "";

        for(char c : s){
            freq[c]++;
        }

        vector<pair<char,int>> res(freq.begin(),freq.end());

        sort(res.begin(),res.end(),[](pair<char,int>& a, pair<char,int>& b ){
            return a.second > b.second;
        });

        for(int i=0; i<res.size(); i++){
            for(int j=0; j<res[i].second; j++){
                ans.push_back(res[i].first);
            }
        }

        return ans;
    }
};