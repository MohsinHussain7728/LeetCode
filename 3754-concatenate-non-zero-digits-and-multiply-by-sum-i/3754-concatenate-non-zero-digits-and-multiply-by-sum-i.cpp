class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int sum = 0;
        int r = 1;

        while(n>0){
            int d = n % 10;
            n = n/10;
            if(d == 0) continue;
            x = d*r+x;
            sum += d;
            r *= 10;
        }

        return x*sum;
    }
};