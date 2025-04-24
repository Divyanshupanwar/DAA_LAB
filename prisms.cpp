#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
    map<T,list<pair<T,int>>>adj;
    void addEdge(T u,T v,int w,bool direction = true){
          
          adj[u].push_back(make_pair(v,w));
        //   if(!direction)adj[v].push_back(make_pair(u,w));
    }
    void display(){
         cout<<"printig adjlist:"<<endl;
         for(auto it:adj){
            cout<<it.first<<" -> ";
            for(auto nb :it.second){
                cout<<"{"<<nb.first<<","<<nb.second<<"}"<<" ";
            }
          cout<<endl;

         }
         
    }
    

};

void bfs(Graph<int>& g,int src,vector<bool>&visited){
    queue<int>q;
    int n = g.adj.size();
   
    //initial state maintain 
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<"->";
        for(auto it:g.adj[node]){
            if(!visited[it.first]){
                 visited[it.first] = true;
                 q.push(it.first);

            }

        }
    }
      
}

void bfs_main(Graph<int>&g){
    
    cout<<"bfs for non connected graph"<<endl;
    int n = g.adj.size();
    vector<bool>visited(n,false);

    for(auto it:g.adj){
         if(!visited[it.first])
         bfs(g,it.first,visited);
    }
     
}

void utill(Graph<int>&g,vector<bool>&visited,int src){
    visited[src] = true;
    cout<<src<<" ";
    for(auto it:g.adj[src]){
        if(!visited[it.first]){
            utill(g,visited,it.first);
        }
    }
}
void dfs(Graph<int>& g,int src){
    int n = g.adj.size();
 vector<bool>visited(n,false);
   for(auto it:g.adj){
        if(!visited[it.first])
        utill(g,visited,it.first);
   }
   
}
bool cycle_detect(Graph<int>&g,int src){
    queue<int>q;
    int n = g.adj.size();
    q.push(src);
    vector<bool>visited(n,false);
    visited[src] = true;
    vector<int>parent(n);
    parent[src] = -1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto it:g.adj[front]){
            int child = it.first;
            if ( parent[front] == child){
 
                  continue;
            }
            else if(!visited[child]){
                 visited[child] = true;
                 parent[child] = front;
                 q.push(child);

            }
            else if(visited[child]){
                 return true;
            }


        }
        

         
    }
    return false;
}
 void topological(Graph<int>&g,int n){
    queue<int>q;
    map<int,int>mp;
   for(auto it:g.adj){
        for(auto i:it.second){
              mp[i.first]++;
        }    
   }
   for(int i = 0;i<n;i++){
         if(mp[i] == 0){
            q.push(i);
         }
   }
   while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<" ";
        for(auto it:g.adj[front]){
              int val = it.first;
              mp[val]--;
              if(mp[val] == 0){
                q.push(val);

              }

        }
    
   }
     
}
vector<int>shortest_path(Graph<int>&g,int src,int dest){
     queue<int>q;
     q.push(src);
     vector<int>parent(g.adj.size(),-1);
     vector<bool>visited(g.adj.size(),false);
     visited[src] = true;
     while(!q.empty()){
          int front = q.front();
          q.pop();
          for(auto it:g.adj[front]){
              if(!visited[it.first]){
                   visited[it.first] = true;
                   parent[it.first] = front;
                   q.push(it.first);
                 
              } 
             
          }
     }
     vector<int>ans;
     while(dest != -1){
        ans.push_back(dest);
        dest = parent[dest];

     }
     reverse(ans.begin(),ans.end());
    return ans;

      
}
void df(Graph<int>&g,int src,stack<int>&st,vector<bool>&visited){
     visited[src] = true;
     for(auto it:g.adj[src]){
           if(!visited[it.first]){
                df(g,it.first,st,visited);
               
           }

     }
     st.push(src);

      
}
void ssp(Graph<int>&g,stack<int>&st,int dest){
    //distance array for every node from src top destination
    vector<int>dist(g.adj.size(),INT_MAX);
    int src = st.top();
    st.pop();
    dist[src] = 0;
    for(auto it:g.adj[src]){
          if(dist[src] +it.second < dist[it.first]){
              dist[it.first] = dist[src] +it.second;    
                  
          }
    }
    while(!st.empty()){
           int src = st.top();
           st.pop();
           for(auto it:g.adj[src]){
            if(dist[src] +it.second < dist[it.first]){
                dist[it.first] = dist[src] +it.second;    
                    
            }

         }
}
cout<<"printing SSP"<<endl;
for(int i = 0;i<dist.size();i++){
      cout<<i<<"-> "<<dist[i]<<endl;

}

 }
 void Dijkstra(Graph<int>&g,int src,int dest){
   // int maxNode = 0;
    // for (auto it : g.adj) {
    //     maxNode = max(maxNode, it.first); // max node number
    //     for (auto p : it.second) {
    //         maxNode = max(maxNode, p.first); // neighbors ka max node number
    //     }
    // }
     int maxNode = g.adj.size();
    
    // Maximum node number ke according dist aur visited array size allocate karo
    vector<int> dist(maxNode + 1, INT_MAX); // +1 to include the maxNode itself
   
    set<pair<int,int>>sp;
    //initial state :{0,src}
    sp.insert({0,src});
    dist[src] = 0;
    while(!sp.empty()){
        auto top =  sp.begin();
        pair<int,int> topel = *top;
        sp.erase(sp.begin());
        int topdist = topel.first;
        int topnode = topel.second;
        for(auto it:g.adj[topnode]){
            if(topdist +it.second < dist[it.first]){
                   auto temp = sp.find({dist[it.first],it.first});
                   if(temp != sp.end()){
                          sp.erase(temp);

                   }
                   dist[it.first] = topdist +it.second;
                   sp.insert({dist[it.first],it.first});

                     
            }
        }

     }

if (dist[dest] == INT_MAX) {
    cout << "No path from " << src << " to " << dest << endl;
} else {
    cout << "Shortest Distance from " << src << " to " << dest << " is " << dist[dest] << endl;
}

}
void bellman(Graph<int>&g,int src,int n){
      vector<int>dist(n,INT_MAX);
      dist[src] = 0;
      //Relaxation
      for(int i = 1;i<n;i++){
          for(auto it:g.adj){
                for(auto a:it.second){
                      int u = it.first;
                      int v = a.first;
                      int w = a.second;
                      if( dist[u] != INT_MAX && w + dist[u] < dist[v]){
                           dist[v] = w + dist[u];

                      }

                }
          }
            
      }
      //distance array has been updated 
      //for detecting  negative Cycle 
      bool update = false;
      for(auto it:g.adj){
        for(auto a:it.second){
              int u = it.first;
              int v = a.first;
              int w = a.second;
              if(dist[u]!= INT_MAX && w + dist[u] < dist[v]){
                update = true;
                   dist[v] = w + dist[u];

              }
              
        }
    }
    if(update){
        cout<<"negative cycle present:"<<endl;

    }
    else cout<<"negative cycle NOt present:"<<endl;
    

    if(!update){
     for(int i = 0;i<dist.size();i++){
           cout<<i<<" ->"<<dist[i]<<endl;

     }

    }



}
void floyd(Graph<int>&g,int n){

       vector<vector<int>>dist(n,vector<int>(n,1e9));
       for(int i = 0;i<n;i++){
            dist[i][i] = 0;            //diagonal 
          }
       //Distances fron graph
       for(auto it:g.adj){
             for(auto v:it.second){
                 int u = it.first;
                 int V = v.first;
                 int w = v.second;
                 dist[u][V] = w;

             }
       }
       for(int k = 0;k <n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dist[i][k] < 1e9 && dist[k][j] < 1e9)
                       dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                 }
             }
         }
         cout<<"PRINITNG MULTIPLE SHORTEST PATH:"<<endl;

       for(int i = 0;i<n;i++){
             for(int j = 0;j<n;j++){
                 cout<<i<<"-"<<j<<":"<<dist[i][j]<<" ";
             }
            cout<<endl;
       }
   }
 


void prisms(Graph<int>& g, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> MST(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    auto start = g.adj.begin()->first;
    key[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (MST[u]) continue;
        MST[u] = true;
        
        for (auto it : g.adj[u]) {
            int v = it.first;
            int w = it.second;
            
            if (!MST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }

    cout << "PRINTING MST USING PRIMS:\n";
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
}



int main(){
	Graph<int> g;
    vector<vector<int>>v = {  {0,0,7,5,0,0,0}, {0,0,8,5,0,0,0},{7,8,0,9,7,0,0},{5,0,9,0,15,6,0},{0,5,7,15,0,8,9},{0,0,0,6,8,0,11},{0,0,0,0,9,11,0}};
    for(int i = 0;i <v.size();i++){
          for(int j = 0;j<v.size();j++){
               if(v[i][j] != 0){
                  g.addEdge(i,j,v[i][j]);

               }
          }
    }
	g.display();
    prisms(g,7);
    // floyd(g,5);
    
   // bellman(g,0,5);
    //Dijkstra(g,6,4);
   // bfs(g,0);
//    bfs_main(g);
//    cout<<"printing dfs:"<<endl;
//    dfs(g,0);
//cout<<"cycle or not:"<<cycle_detect(g,0)<<endl;
//    vector<int>temp = shortest_path(g,0,3); 
//    for(auto it:temp){
//      cout<<it<<" ";
//    }
// vector<bool>visited(g.adj.size(),false);
// stack<int>st;
// int src = 0;
// df(g,src,st,visited);
// ssp(g,st,3);
     




    return 0;
}