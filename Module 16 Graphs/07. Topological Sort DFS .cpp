#include <bits/stdc++.h> 
#include<unordered_map>
#include<stack>
#include<list>

void DFSTopological(unordered_map<int, list<int>>&adjLIST,vector<bool>&visited,
                    stack<int>&s, int node){
        
        visited[node] = true;
        for(auto neighbour : adjLIST[node]){
            if(!visited[neighbour])
                DFSTopological(adjLIST, visited, s, neighbour);
        }
        s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>ans;
    unordered_map<int, list<int>>adjLIST;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // directed graph
        adjLIST[u].push_back(v);
    }
    // Time limit exceeded using unordered_map is not always optimised
    // in cases of accessing value, assigning a value arrays/ vectors are optimised data structures 
    vector<bool>visited(v,0);
    //unordered_map<int, bool>visited;
    stack<int>s;
    for(int i=0; i<v; i++){
        if(!visited[i])
            DFSTopological(adjLIST, visited, s, i);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
