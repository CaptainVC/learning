//time complexity O(V+E)
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void bfs(int s)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        list<int> q;

        visited[s] = true;
        q.push_back(s);

        list<int>::iterator i;

        while (!q.empty())
        {
            s = q.front();
            cout << s << "";
            q.pop_front();
            for (i = adj[s].begin(); i != adj[s].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    q.push_back(*i);
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g(0);
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    cout << "BFS starting from node 2\n";
    g.bfs(2);

    return 0;
}
