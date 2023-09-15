
#include<unordered_map>
#include<list>

void DFSTraversal(unordered_map<int,list<int>>&adjLIST,unordered_map<int, bool>&visited,vector<int>&temp,int node ){

        temp.push_back(node);
        visited[node] = true;

        // Recursive call for connected nodes
        for(auto i : adjLIST[node]){
            if(!visited[i]){
                DFSTraversal(adjLIST,visited, temp, i);
            }
        }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>ans;

    // Mapping is Given in edges matrix
    // create a adjacency list from that mapping matrix
    unordered_map<int,list<int>>adjLIST;
    for(int i=0; i<E; i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adjLIST[u].push_back(v);
        adjLIST[v].push_back(u);

    }

    // adjacency list is created 
    unordered_map<int, bool>visited;

    for(int i=0; i<V; i++){

        if(!visited[i]){
            vector<int>temp;
            DFSTraversal(adjLIST, visited, temp, i);
            ans.push_back(temp);
        }
    }
    return ans;
}

// DFS Traversal in connected undirected graph
class Solution {
  public:
  
    void DFSTraversal(vector<int> adj[], unordered_map<int, bool>&visited, vector<int>&ans, int node ){
        
        ans.push_back(node);
        visited[node] = true;

        // Recursive call for connected nodes
        for(auto i : adj[node]){
            if(!visited[i]){
                DFSTraversal(adj,visited, ans, i);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>ans;
        unordered_map<int, bool>visited;
        
        DFSTraversal(adj, visited, ans, 0);
        
        return ans;
        
    }
};
