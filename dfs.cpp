//time complexity O(V+E)
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
  map<int, bool> visited;
  map<int, list<int>> adj;

  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
  }

  void dfsUtil(int v) //for handling disconnected graph
  {
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
      if (!visited[*i])
        dfsUtil(*i);
    }
  }

  void dfs()
  {
    for (auto i : adj)
    {
      if (visited[i.first] == false)
        dfsUtil(i.first);
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 9);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(9, 3);

  cout << "DFS starting from node 2\n";
  g.dfs();

  return 0;
}