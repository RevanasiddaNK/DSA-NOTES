#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>
#include<limits.h>
#include<vector>
using namespace std;
class Graph{
    public:
        unordered_map<int, list<pair<int,int>>>adjList;
        void addEdge(int u, int v, int wt){
            pair<int,int>p;
            p.first = v;
            p.second = wt;
            adjList[u].push_back(p);    
        }

        void display(){
            for(auto i:adjList){
                cout<<i.first<<" -> ";
                for(auto j : i.second){
                    cout<<j.first<<"  "<<j.second<<" , ";
                }
                cout<<endl;
            }
        }

        void DFS(int i,vector<int>&visited, stack<int>&topo){
            visited[i] = 1;
            for(auto j : adjList[i]){
                if(visited[j.first] != 1){
                    DFS(j.first,visited,topo);
                }
            }
            topo.push(i);
        }

        void GetShortestPath(stack<int>topo){
            
            vector<int>distance(6, INT_MAX);
            distance[1] = 0;
            while(!topo.empty()){
                int top = topo.top();
                topo.pop();
                if(distance[top] != INT_MAX){
                    for(auto i : adjList[top]){
                        if((distance[top]+i.second) < distance[i.first]){
                            distance[i.first] = distance[top]+i.second;
                        }
                    }
                }
            }

            for(int i=0; i<distance.size(); i++){
                cout<<distance[i]<<" ";
            }
            cout<<endl;

        }
};

int main(){
    Graph G;
    // add all edges to graph
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);

    // G.display();

    // Get Topological Linear Order
    vector<int>visited(6, 0);
    stack<int>topo;
    for(int i=0; i<6; i++){
        if(visited[i] != 1){
            G.DFS(i,visited,topo);
        }
    }

    G.GetShortestPath(topo);
    return 0;
}

// output :
/*
2147483647 0 2 6 5 3 
*/


// getShortPath can be written like this
void GetShortestPath(stack<int>topo, vector<int>&distance){
            distance[1] = 0;
            while(!topo.empty()){
                int top = topo.top();
                topo.pop();
                if(distance[top] != INT_MAX){
                    for(auto i : adjList[top]){
                        if((distance[top]+i.second) < distance[i.first]){
                            distance[i.first] = distance[top]+i.second;
                        }
                    }
                }
            }
 }
