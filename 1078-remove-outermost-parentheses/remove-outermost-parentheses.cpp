class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int count = 0;
        // bool isFirstBracket = true;
        string ans = "";

        for(char c : s){
            if(c == '(' && count == 0){
                count++;
            }else if(c == '('){
                ans.push_back(c);
                count++;
            }else if(c == ')'){
                count--;
                if(count != 0){
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};