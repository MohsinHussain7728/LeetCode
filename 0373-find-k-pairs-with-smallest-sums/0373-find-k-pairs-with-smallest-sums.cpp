class Solution {
public:

    struct cmp{
        bool operator()(const pair<long long,pair<int,int>>&a, const pair<long long,pair<int,int>>&b){
            return a.first > b.first; //min heap
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, cmp> pq; //min heap

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         long long sum = 1LL * nums1[i] + 1LL * nums2[j];

        //         pq.push({sum,{nums1[i],nums2[j]}});

        //         if(pq.size()>k)
        //             pq.pop(); 
        //     }
        // }

        int size = min(n,k);

        for(int i=0; i<size; i++){
            pq.push({1LL * nums1[i] + nums2[0], {i,0}});
        }

        vector<vector<int>> ans;

        while(k>0 && !pq.empty()){ // TC->O(klogk) ,, SC->O(k)
            auto p = pq.top();
            long long sum = p.first;
            int i = p.second.first;
            int j = p.second.second;

            pq.pop();

            ans.push_back({nums1[i],nums2[j]});

            if(j+1 < m){//push 1st elem of current row 
                pq.push({1LL * nums1[i] + nums2[j+1] , {i,j+1}});
            }

            k--;
        }

        

        // while(!pq.empty()){
        //     vector<int>temp;
        //     pair<int,int>p1;

        //     p1 = pq.top().second;
        //     temp.push_back(p1.first);
        //     temp.push_back(p1.second);
        //     ans.push_back(temp);

        //     pq.pop();
        // }

        return ans;
    }
};