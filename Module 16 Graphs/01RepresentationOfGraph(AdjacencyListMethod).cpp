#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>

class Graph{

    public:

    unordered_map<T, list<T>>adj;

    void addEdge(T U, T V, bool direction){
        // direction == 0 undirectional
        // direction == 1 directional
        adj[U].push_back(V);
        if(direction == 0){
            // Undirectional both directions
            adj[V].push_back(U);
        }
    }

    void PrintAdjList(){

        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    Graph<int>G;

    int numNodes, numEdges;
    cout<<"Enter number of Nodes & Edges \n";
    cin>>numNodes>>numEdges;

    cout<<"Enter Nodes along with Edges \n";
    for(int i=0; i<numEdges; i++){
        int U,V;
        bool direction = 0;
        cin>>U>>V;
        G.addEdge(U,V,direction);
    }
    
    G.PrintAdjList();

    return 0;
    
}