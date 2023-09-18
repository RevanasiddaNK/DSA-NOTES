#include<unordered_map>
#include<list>
#include<queue>

int detectCycleInDirectedGraph(int n, vector<pair<int,int>>&edges) {
    
    int count = 0;
    int v = edges.size();
    unordered_map<int, list<int>>adjLIST;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first-1;
        int v = edges[i].second-1;

        // directed graph
        adjLIST[u].push_back(v);
    }

    vector<int>indegree(n,0);
    // find indegree of all nodes
    for(auto node : adjLIST){
        for(auto neighbour: node.second)
            indegree[neighbour]++;
    }

    queue<int>q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    // BFS Algorithm
    while(!q.empty()){

        int front = q.front();
        q.pop();

        count++;

        for(auto neighbour : adjLIST[front])
            indegree[neighbour]--;

        for(auto neighbour : adjLIST[front]){
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if(count == n)
      return 0;
    else
      return 1;
}
