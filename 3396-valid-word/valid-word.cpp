class Solution {
public:
    bool isValid(string word) {
        
        bool vowel = 0, consonant = 0;
        string vowels = "aeiouAEIOU";

        if(word.length()<3) return false;

        for(char ch: word){
            if(isalpha(ch)){
                if(vowels.find(ch) != string::npos){
                    vowel = true;
                }else{
                    consonant = true;
                }
            }else if(!isdigit(ch)){
                return false;
            }
        }

        return vowel && consonant;
    }
};