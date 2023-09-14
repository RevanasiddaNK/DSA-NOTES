vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>&edges) {
        
        vector<vector<int>>neghbours(n);
        vector<vector<int>>ans(n);
        
        for(int i=0; i<n; i++){
            neghbours[i].push_back(i);
        }
        
        for(int i=0; i<m; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            neghbours[u].push_back(v);
            neghbours[v].push_back(u); 
                       
        }
        
        return neghbours;        
}
