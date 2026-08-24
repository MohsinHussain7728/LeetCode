class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        long sum = 0;
        long prod = 1;

        int d = -1;

        while(temp > 0){
            d = temp % 10;

            sum += d;
            prod *= d;

            temp/= 10;
        }

        if((long)n % (sum+prod) == 0)
            return true;

        return false;
    }
};