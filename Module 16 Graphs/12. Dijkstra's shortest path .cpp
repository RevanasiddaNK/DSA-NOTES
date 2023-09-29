#include <bits/stdc++.h> 
#include<unordered_map>
#include<set>
#include<list>
#include<limits.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int,int>>>adjList;
    for(int i=0; i<edges; i++){
        
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        // int u=0,v=0,wt=0;

        // un directed graph
        adjList[u].push_back(make_pair(v,wt));
        adjList[v].push_back(make_pair(u,wt));
    }
    set<pair<int, int>>st;
    vector<int>Distance(vertices,INT_MAX);
    Distance[source] = 0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        auto top = *(st.begin());
        st.erase(st.begin());
        int topMin = top.second;
        int topDis = top.first;
        for(auto i : adjList[topMin]){
            if(topDis+i.second < Distance[i.first]){
                auto record = st.find(make_pair(Distance[i.first],i.first));
                // (i.first) element present in set
                if(record != st.end()){
                    st.erase(record);
                }
                Distance[i.first] = topDis+i.second;
                st.insert(make_pair(topDis+i.second, i.first));
            }
        }  
    }
    return Distance;
}
