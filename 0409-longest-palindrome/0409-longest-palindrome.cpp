class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;

        for(char &ch: s){
            mpp[ch]++;
        }

        bool odd = false;
        int res = 0;

        for(auto &it: mpp){
            int val = it.second;
            if(val % 2 == 0)
                res += val;

            if(val%2 == 1)
                odd = true;
        }

        if(odd == false)
            return res;

        for(auto &i : mpp){
            int val = i.second;
            if(val % 2 == 1)//a->3 ,, b->5 ::-> take pair:can easily make palindrome :- aa ,, bbbb
                res += val-1;
        }

        return res+1;//any char can be inserted in middle odd no. of times
    }
};