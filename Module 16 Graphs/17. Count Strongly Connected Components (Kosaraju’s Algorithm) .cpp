// KOSARAJU'S ALGORITHM
/*
Auxillary
time complexity = O(E+N)
space complexity = O(E)
*/

#include<unordered_map>
#include<list>
#include<stack>

void dfs(int node,vector<bool>&visited,unordered_map<int,list<int>>&adj){
	visited[node] = true;
	for(auto nbr : adj[node]){
		if(!visited[nbr])
			dfs(nbr,visited,adj);
	}
}

void dfsTopo(int node,vector<bool>&visited,stack<int>&topo,unordered_map<int,list<int>>&adj){
	visited[node] = true;
	for(auto nbr : adj[node]){
		if(!visited[nbr])
			dfsTopo(nbr,visited,topo,adj);
	}
	topo.push(node);
}

int stronglyConnectedComponents(int vertex, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>>adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}

	vector<bool>visited(vertex,0);
	stack<int>topo;
	for(int i=0; i<vertex; i++){
		if(!visited[i]){
			dfsTopo(i,visited,topo,adj);
		}
	}

	// reverse the graph to seperate all the strongly connected components of a Graph
	unordered_map<int,list<int>>adjTranspose;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adjTranspose[v].push_back(u);
	}
	
	for(int i=0; i<visited.size(); i++)
		visited[i] = false;

	int count = 0;
	while(!topo.empty()){
		int top = topo.top();
		topo.pop();
		if(!visited[top]){
			count++;
			dfs(top,visited,adjTranspose);
		}
	}
	return count;
}
