#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int v;
    vector<list<int>> adj;
    Graph(int vertices) : v(vertices), adj(vertices) {};
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void display()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (auto it : adj[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
};
void utill(Graph &g, int src, vector<bool> &visited)
{
    visited[src] = true;
    cout << src << " ";
    for (auto it : g.adj[src])
    {
        if (!visited[it])
            utill(g, it, visited);
    }
}

void dfs(Graph &g, int src)
{
    int v = g.v;
    vector<bool> visited(v, false);
    utill(g, src, visited);
}
bool utill1(Graph &g, int src, vector<bool> &visited, vector<bool> &inRecursionStack)
{
    visited[src] = true;
    inRecursionStack[src] = true;

    for (auto it : g.adj[src])
    {
        if (!visited[it])
        {

            if (utill1(g, it, visited, inRecursionStack))
                return true;
        }
        else if (inRecursionStack[it])
        {
            return true;
        }
    }
    inRecursionStack[src] = false;
    return false;
}

bool dfs1(Graph &g, int src)
{
    int v = g.v;
    vector<bool> visited(v, false);
    vector<bool> inRecursionStack(v, false);
    return utill1(g, src, visited, inRecursionStack);
}

void bfs(Graph &g, int src)
{
    int v = g.v;
    vector<bool> visited(v, false);
    queue<int> q;
    visited[src] = true;
    q.push(src);
    ;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        for (auto it : g.adj[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    cout << endl;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);


    cout << "cycle or not:" << dfs1(g, 0) << endl;
    g.display();

    return 0;
}