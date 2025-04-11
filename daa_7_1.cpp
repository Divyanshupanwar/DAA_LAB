#include <bits/stdc++.h>
using namespace std;
class info{
    public:
    int src,dest,weight;
    info(int src,int dest,int weight){
         this->src = src;
         this->dest = dest;
         this->weight = weight;

    }

};
class compare{
    public:
    bool operator()(const info &a,const info &b){
           return a.weight < b.weight;
    }
};
class Graph
{
public:
    int v;
    vector<list<pair<int,int>>> adj;
    Graph(int vertices) : v(vertices), adj(vertices) {};
    void addEdge(int u, int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    void display()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (auto it : adj[i])
            {
                cout << "{"<<it.first << ","<<it.second<<"}";
            }
            cout << endl;
        }
    }
};
int find(int u,vector<int>&parent){
      if(parent[u] == u)return u;
      return parent[u] = find(parent[u],parent);
}
void  union_set(int u,int v,vector<int>&parent){
     int pu = find(u,parent);
     int pv = find(v,parent);
     if(pu != pv){
         parent[pv] = pu;
     }
}
void krushkal(Graph &g){
      priority_queue<info,vector<info>,compare>pq;
      vector<vector<bool>>visited(g.v,vector<bool>(g.v,false));
      for(int i = 0;i< g.v;i++){
            for(auto it:g.adj[i]){
                 if(!visited[i][it.first] &&  !visited[it.first][i]){
                      pq.push(info(i,it.first,it.second));
                      visited[i][it.first] = true;
                      visited[it.first][i] = true;
                 }
            }
      }
     vector<int>parent(g.v);
     for(int i = 0;i<g.v;i++){
          parent[i] = i;
     }
     int cost = 0;
     while(!pq.empty()){
         info temp = pq.top();
         pq.pop();
         if(find(temp.src,parent) != find(temp.dest,parent)){
            cout<<temp.src<<"->"<<temp.dest<<endl;
              cost += temp.weight;
            union_set(temp.src,temp.dest,parent);

         }
     }
     cout<<"total min  cost(KRUSHKAL) :"<<cost<<endl;


}



int main()
{
    Graph g(5);
    g.addEdge(0, 1,10);
    g.addEdge(0, 3,30);
    g.addEdge(1,2,5);
    g.addEdge(2, 3,25);
    g.addEdge(3, 4,7);

     
    g.display();
    cout<<endl<<endl;
    krushkal(g);

    return 0;
}