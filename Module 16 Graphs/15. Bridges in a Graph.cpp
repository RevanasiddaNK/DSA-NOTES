/*
Time Complexity = O(E+V)
Space Complexity = O(V)
*/

#include<unordered_map>
#include<list>

void dfs(int node,int parent,unordered_map<int,list<int>>&adj,vector<int>&Disc,vector<int>&Low,
        vector<bool>&visited,vector<vector<int>>&ans,int &timer){

            visited[node] = true;
            Disc[node] = Low[node] = timer++;
            for(auto nbr : adj[node]){

                if(nbr == parent)
                    continue;
                
                if(!visited[nbr]){
                    dfs(nbr,node,adj,Disc,Low,visited,ans,timer);
                    Low[node] = min(Low[node],Low[nbr]);
                    if(Low[nbr] > Disc[node]){
                       vector<int>temp;
                       temp.push_back(node);
                       temp.push_back(nbr);
                       ans.push_back(temp); 
                    }
                }
                else{
                    // Back Edge Case
                    Low[node] = min(Low[node],Disc[nbr]);
                }

            }

        }

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    vector<vector<int>>ans;

   // Adjacency list creation 
   unordered_map<int, list<int>>adj;
   for(int i=0; i<e; i++){
       int u = edges[i][0];
       int V = edges[i][1];

       adj[u].push_back(V);
       adj[V].push_back(u);
   }

    vector<bool>visited(v,false);
    vector<int>Disc(v,-1);
    vector<int>Low(v,-1);

    int timer = 0;
    int parent = -1;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i,parent,adj,Disc,Low,visited,ans,timer);
        }
    }
    return ans;
}
