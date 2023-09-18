
#include <bits/stdc++.h> 
#include<unordered_map>
#include<queue>
#include<list>


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    vector<int>ans;
    unordered_map<int, list<int>>adjLIST;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // directed graph
        adjLIST[u].push_back(v);
    }

    vector<int>indegree(v,0);
    // find indegree of all nodes
    for(auto node : adjLIST){
        for(auto neighbour: node.second)
            indegree[neighbour]++;
    }

    queue<int>q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    // BFS Algorithm
    while(!q.empty()){

        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour : adjLIST[front])
            indegree[neighbour]--;

        for(auto neighbour : adjLIST[front]){
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}
