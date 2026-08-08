class Solution {
public:

    long func(int m, int n, int guess){
        int row = m;
        int col = 1;

        long cnt = 0;

        while(row>=1 && col<=n){
            if(row*col <= guess){
                cnt += row;
                col+=1;
            }else{
                row-=1;
            }
        }

        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
        long low = 1;
        long high = m*n;

        long ans = -1;

        long row = m;
        long col = 1; 

        while(low<=high){
            long mid = low + (high-low)/2;

            long cnt = func(m,n,mid);

            if(cnt < k){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1; // search for 1st occr
            }
        }

        return (int)ans;
    }
};