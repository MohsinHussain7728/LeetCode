class Solution {
public:

    static bool cmp(const vector<int>&a , const vector<int>&b){
        if(a[0] == b[0])
            return a[1] > b[1];//if same start, larger end first

        return a[0] < b[0]; // smaller start first
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),cmp);

        int end=-1, res =0;

        for(int i=0; i<intervals.size(); i++){
            
            int currEnd = intervals[i][1];

            if(currEnd>end){
                res++;
                end = currEnd;
            }

            // d = max(b,d);
        }

        return res;
    }
};