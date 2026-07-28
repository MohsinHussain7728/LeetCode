class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;

        while(l<r){
            while(l<r && !isalnum(s[l])){//skip all non-alpha numeric char
                l++;
            }

            while(l<r && !isalnum(s[r])){
                r--;
            }

            if(tolower(s[l]) == tolower(s[r])){
                l++;
                r--;
            }else{
                return false;
            }
        }

        return true;
    }
};