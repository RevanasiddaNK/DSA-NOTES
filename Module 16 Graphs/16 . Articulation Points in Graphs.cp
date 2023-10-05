/*
Time Complexity = O(E+N)
Space Complexity = O(4*E) = O(E)

Approach :
it is similar to bridges problem 
number of articulation points in the closed loop is Zero
number of articulation points in the straight chain is equal to the number of Nodes in the straight chain

starting element is handled seperately
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include <vector>

using namespace std;

int min(int a, int b){
    if(a > b)
        return b;
    return a;
}

void dfs(int node,int parent,vector<bool>&visited,int &timer,vector<int>&disc,vector<int>&low,vector<bool>&artPoints,unordered_map<int,list<int>>adj){

    disc[node] = low[node] = timer++;
    visited[node] = true;

    int child = 0;
    for(auto nbr : adj[node]){

        if(nbr == parent)
            continue;

        if(!visited[nbr]){
            dfs(nbr,node,visited,timer,disc,low,artPoints,adj);
            low[node] = min(low[node],low[nbr]);

            if(low[nbr] >= disc[node] && parent != -1){
                artPoints[node] = true;
            }
            child++;
        }
        else{
            // circulr loop
            // Back Edge case
            low[node] = min(low[node],low[nbr]);
        }
    }
    if(parent == -1 && child > 1 ){
        artPoints[node] = true;
    }

}

int main(){

    int E = 5,N = 5;
    vector<pair<int,int>>edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int,list<int>>adj;

    for(int i=0; i<E; i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int timer = 0;
    int parent = -1;
    vector<int>disc(E,-1);
    vector<int>low(E,-1);
    vector<bool>visited(E,false);
    vector<bool>artPoints(E,false);

    for(int i=0; i<E; i++){
        if(!visited[i]){
            dfs(i,parent,visited,timer,disc,low,artPoints,adj);
        }
    }

    cout<<"Articulation Points are : \n";
    for(int i=0; i<E; i++){
        if(artPoints[i] == true)
            cout<<i<<" ";
    }
    return 0;
}
