class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n == 0) return 0;

        int lastDigit= 0;
        vector<int>arr;

        while(n>0){//(log10n)
            lastDigit = n % 10;
            if(lastDigit != 0)
                arr.push_back(lastDigit);
            
            n = n / 10;
        }

        reverse(arr.begin(),arr.end());

        long long x = 0;
        long long sum =0;

        for(int &digit: arr){//(arr.length)
            x = x*10 + digit;
            sum += digit;
        }

        return x*sum;
    }
};