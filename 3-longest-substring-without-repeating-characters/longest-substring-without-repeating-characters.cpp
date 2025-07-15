class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> m;
        int l = 0, r = 0, len = 0;

        while(r < s.length()){
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }
            m[s[r]] = r;
            len = max(len, r - l + 1);
            r++;
        } 

        return len;
    }
};