#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<limits.h>
#include<vector>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int,int>>>adjList;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    
    vector<bool>MST(n+1,false);
    vector<int>Key(n+1,INT_MAX);
    vector<int>parent(n+1,-1);

    Key[1] = 0;
    parent[1] = -1;

    for(int i=0; i<n; i++){

// find out Min Node U from the key array
        int min = INT_MAX,U;
        for(int i=1;i<=n; i++){
            if(MST[i] == false && Key[i]<min){
                min = Key[i];
                U = i;
            }
        }

        MST[U] = true;

        for(auto i : adjList[U]){
            int V = i.first;
            int W = i.second;
            if(MST[V] == false && W < Key[V]){
               Key[V] = W;
               parent[V] = U;
            }
        }
    }

    vector<pair<pair<int, int>, int>>ans;
    for(int i=2; i<=n; i++){
        ans.push_back(make_pair(make_pair(parent[i],i),Key[i]));
    }
    return ans;
}
