class Solution {
public:
    bool checkInclusion(string s1, string s2) {//TC->O(n+m) ,, SC->O(26)
        int n = s1.length();
        int m = s2.length();

        vector<int> hash1(26,0);
        vector<int> hash2(26,0);

        for(char &ch : s1){//O(n)
            hash1[ch-'a']++;
        }

        int l=0, r=0;

        while(r<m){//O(m)
            hash2[s2[r] - 'a']++;
            
            if(r-l+1 > n){
                hash2[s2[l] - 'a']--;
                l++;
            }

            if(hash1 == hash2)
                return true;

            r++;
        }

        return false;
    }
};