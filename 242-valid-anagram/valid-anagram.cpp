class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<char,int> freq;

        for(char c: s){
            freq[c]++;
        }

        for(char c: t){
            if(freq[c] == 0) return false;
            freq[c]--;
        }

        return true;
        
    }
};