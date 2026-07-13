    class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int>ans;
            int l =low, h = high;

            string s = "123456789";

            int len1=0 , len2=0;

            while(l>0){
                len1++;
                l /= 10;
            }

            while(h > 0){
                len2++;
                h /= 10;
            }


            for(int i=len1; i<=len2; i++){
                for(int start = 0; start<10-i; start++){
                    string sub = s.substr(start,i);
                    int num = stoi(sub);

                    if(num>=low && num<=high)
                        ans.push_back(num);
                }
            }

            return ans;
        }
    };