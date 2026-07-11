class Solution {
public:

    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis, int& vCnt, int& eCnt){
        vis[node] = 1;
        vCnt += 1;
        eCnt += adj[node].size();//neighbors of node.

        //loop over neighbours
        for(int j=0; j<adj[node].size(); j++){
            int neigh = adj[node][j];

            if(vis[neigh] == false){
                dfs(adj,neigh,vis,vCnt, eCnt);
            }

        } 
    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(int i=0; i<edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];

            //Undirected Graph
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }

        int cnt = 0;
        vector<bool>vis(n,0);

        for(int i=0; i<n; i++){
            int vertexCnt = 0;
            int edgeCnt = 0;
            if(!vis[i]){
                dfs(adj,i,vis,vertexCnt,edgeCnt);

                edgeCnt /= 2;

                if((vertexCnt * (vertexCnt-1) /2) == edgeCnt)
                    cnt += 1;
            }
        }

        return cnt;
    }
};