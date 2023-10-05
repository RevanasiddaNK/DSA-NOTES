/*
Bell Man ford Algorithm
Time Complexity = O(V*E)
Space Complexity = O(V)

*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>distance(V, 1e8);
        distance[S] = 0;
        
        // by taking consideration of all Nodes 0 to N
        for(int i=0; i<V; i++){
            for(int j=0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(distance[u] != 1e8 && distance[u]+wt < distance[v]){
                    distance[v] = distance[u]+wt;
                }
            }
        }
        
        bool flag = false;
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(distance[u] != INT_MAX && distance[u]+wt < distance[v]){
                distance[v] = distance[u]+wt;
                flag = true;
            }
        }
        
        if(flag){
            
            // Negative Cycle is present
            vector<int>ans(1,-1);
            return ans;
        }     
        return distance;
    }
};
