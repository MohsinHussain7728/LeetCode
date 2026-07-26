class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;

        while(n>0){
            int digit = n%10;
            arr.push_back(digit);
            n = n/10;
        }

        reverse(arr.begin(),arr.end());
        long long maxi = LLONG_MIN;

        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                long long multi = arr[i];
                for(int k=0; k<1; k++){
                    multi *= arr[j];
                    maxi = max(multi, maxi);
                }
            }
        }

        return (int)maxi;
    }
};