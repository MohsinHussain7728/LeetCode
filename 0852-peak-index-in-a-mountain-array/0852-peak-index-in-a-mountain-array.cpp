class Solution {
public:

    int BS(vector<int>& arr, int low, int high){
        if(low == high)
            return low;

        int mid = low + (high-low)/2;

        if(arr[mid] < arr[mid+1]){//Still Climbing
            return BS(arr,mid+1,high);
        }
        return BS(arr,low,mid);//maybe standing on peak:: high = mid;
    }

    int peakIndexInMountainArray(vector<int>& arr) {//Look for transition of slope rather than maxm
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low<high){
            int mid = low + (high-low)/2;

            if(arr[mid] < arr[mid+1]){//Still climbing
                low = mid+1;
            }else{
                high = mid; //possible that standing on peak
            }
        }

        return high;

        // return BS(arr,low,high);
    }
};