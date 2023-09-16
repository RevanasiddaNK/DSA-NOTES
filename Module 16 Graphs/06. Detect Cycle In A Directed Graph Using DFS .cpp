#include<unordered_map>
#include<list>

bool checkCyclicDFS(unordered_map<int, list<int>>&adjLIST, unordered_map<int, bool>&visited,
                    unordered_map<int, bool>&DFSvisited,int node){

      visited[node] = 1;
      DFSvisited[node] = 1;

      for(auto neighbours : adjLIST[node]){
        if(!visited[neighbours]){
          bool Cyclic = checkCyclicDFS(adjLIST, visited, DFSvisited, neighbours);
          if(Cyclic)
            return 1;
        }
        else if(DFSvisited[neighbours]){
          return 1;
        }
      }
      DFSvisited[node] = 0;
      return 0;
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>>&edges) {
    // create adj list
    unordered_map<int, list<int>>adjLIST;
    for(int i=0; i<edges.size(); i++){
      int u = edges[i].first;
      int v = edges[i].second;
      adjLIST[u].push_back(v);              
    }

    unordered_map<int, bool>visited;
    unordered_map<int, bool>DFSvisited;

    for(int i=0; i<adjLIST.size(); i++){
      if(!visited[i]){
        bool Cyclic = checkCyclicDFS(adjLIST, visited, DFSvisited, i);
        if(Cyclic)
          return 1;
      }
    }
    return 0;
}
