#include<unordered_map>
#include<list>
#include<queue>

// By Using Breadth First Search (BFS)
bool isCyclicBFS(unordered_map<int, list<int>>&adjacencyLIST, unordered_map<int, bool>&visited, 
                unordered_map<int, int>&parent, int node){

        visited[node] = 1;
        parent[node] = -1;
        queue<int>q;
        q.push(node);

        while(!q.empty()){

            int front = q.front();
            q.pop();
        
            for(auto i:adjacencyLIST[front]){

                if(visited[i] && i != parent[front])
                    return 1;

                if(!visited[i]){
                    visited[i] = 1;
                    parent[i] = front;
                    q.push(i);
                }

            }
        }
        return 0;
}

// By Using Depth First Search (DFS)
bool isCyclicDFS(unordered_map<int, list<int>>&adjacencyLIST, unordered_map<int, bool>&visited,
                int parent, int node){

        visited[node] = 1;
        for(auto i:adjacencyLIST[node]){
            if(!visited[i]){
                bool isCyclic = isCyclicDFS(adjacencyLIST, visited, node, i);
                if(isCyclic)
                    return 1;
            }
            else if(i != parent)
                return 1;
        }
        return 0;          
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // n = vertices/ nodes
    // m = edges
    // crate adajacency list from given mappings
    unordered_map<int, list<int>>adjacencyLIST;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjacencyLIST[u].push_back(v);
        // Undirectd Graph
        adjacencyLIST[v].push_back(u);
    }

    // to track cyclic we use visited data structure
    unordered_map<int, bool>visited;
    unordered_map<int, int>parent;
    // Given Graph can Dissconnected
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool isCyclic = isCyclicDFS(adjacencyLIST, visited, -1, i);
            if(isCyclic)
                return "Yes";
        }
    }
    return "No";
}
