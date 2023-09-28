#include<unordered_map>
#include<list>
#include<queue>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Creating Adjacent List from Mapping
	unordered_map<int, list<int>>adjLIST;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adjLIST[u].push_back(v);
		adjLIST[v].push_back(u);
	}

	unordered_map<int, bool>visited;
	unordered_map<int, int>parent;
	queue<int>q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i:adjLIST[front]){
			if(!visited[i]){
				parent[i] = front;
				visited[i] = true;
				q.push(i);
			}
		}
	}

	vector<int>ans;
	ans.push_back(t);
	int i = t;
	while(i != s){
		i = parent[i];
		ans.push_back(i);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
