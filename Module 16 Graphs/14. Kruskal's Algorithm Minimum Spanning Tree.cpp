#include<algorithm>
/* THIS IS ONLY USED IN PRIORITY QUEUES

class cmp{
    bool operator(vector<int>&a, vector<int>&b){
        return a[2] < b[2];
    }
};
*/

// CURLY BRACES SHOULD HAVE OTHER WISE IT WILL GIVE ERROR!
bool cmp(vector<int>&a, vector<int>&b){
    return a[2] < b[2];
}

int findParent(int i,vector<int>&parent){
    if(i == parent[i])
        return i;   
    return parent[i] = findParent(parent[i], parent);
}

void addEdgetoUnionMST(int u, int v, vector<int>&parent, vector<int>&rank){

// this is not required
   // u = findParent(u, parent);
   // v = findParent(v, parent);

    if(rank[u] == rank[v]){
        parent[u] = v;
        rank[v]++;
    }
    else if(rank[u] < rank[v])
        parent[u] = v;
    else
        parent[v] = u;
}

int minimumSpanningTree(vector<vector<int>>&edges, int n)
{
    int MinWeight = 0;

    sort(edges.begin(),edges.end(),cmp);

    vector<int>parent(n);
    //vector<int>rank(n); // this works
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        //rank[i] = 0;
    }
    vector<int>rank(n,0);
    
    for(int i=0; i<edges.size(); i++){
        int u = findParent(edges[i][0], parent);
        int v = findParent(edges[i][1], parent);
        int w = edges[i][2];
        if(u != v){
            MinWeight += w;
            addEdgetoUnionMST(u,v,parent,rank);
        }
    }
    return MinWeight;
}
