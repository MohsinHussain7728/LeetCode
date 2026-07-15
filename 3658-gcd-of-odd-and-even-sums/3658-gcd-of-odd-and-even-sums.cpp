class Solution {
public:

    int gcd(int a, int b){
        if(a == 0 || b==0)
            return max(a,b);

        int res = min(a,b);

        while(res>0){
            if(a % res == 0 && b % res == 0)
                break;
            res--;
        }

        return res;
    }

    int gcdOfOddEvenSums(int n) {
        int sumEven = n*(n+1);
        int sumOdd = n*n;

        return gcd(sumEven, sumOdd);
    }
};