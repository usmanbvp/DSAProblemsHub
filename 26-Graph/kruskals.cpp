// Disjoint set
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:

    vector<int> rank;
    vector<int> parent;

    // constructor to initialize the parent and rank
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        // using path compression approach which will work in constant time
        return parent[node] = findUPar(parent[node]);

        // normal approach with logarithmic complexity
        // return findUPar(parent[node]);
    }

    void unioByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // i.e is the case for cycle
        if(ulp_u == ulp_v){
            return;
        }

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        
        else if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        
    }
};

int main(){
    
    int v,e;
    cout<<"Enter number of vertices : ";
    cin>>v;

    cout<<"Enter number of edges : ";
    cin>>e;
    
    vector<pair<int,pair<int,int>>> edges;

    for(int i = 0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }

    sort(edges.begin(),edges.end());


    vector<pair<int,int>> mst;

    DisjointSet ds(v);

    for(auto i:edges){
        pair<int,pair<int,int>> temp = i;
        int startNode = temp.second.first;
        int endNode = temp.second.second;

        if(ds.findUPar(startNode) != ds.findUPar(endNode)){
            mst.push_back({startNode,endNode});
            ds.unioByRank(startNode,endNode);
        }
    }

    cout<<"Edges in the minimum spanning tree : "<<endl;
    for(auto i:mst){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}

// sample testcase
// Enter number of vertices : 3
// Enter number of edges : 3
// 0 1 10
// 1 2 20
// 0 2 30
// Edges in the minimum spanning tree :
// 0 1
// 1 2