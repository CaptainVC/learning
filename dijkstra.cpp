#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> g[N]; // here first element is node and second element is edge weight

void dijkstra(int source) {
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    
    set<pair<int,int>> st; // here first element is edge weight and second is node because we have to sort w.r.t. edge weight
    dist[source] = 0;
    
    while(st.size() > 0) {
        auto node = *st.begin();  // elements in set are sorted in ascending order T.C is O(1)
        int v = node.second;
        int dis = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto child: g[v]) {
            int child_v = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }

    }
}

int main() {
    int n, m;
    for(int i=0;i<m;i++) {
        int x, y, wt;
        cin>>x>>y>>wt;
        g[x].push_back({y, wt});
    }

    return 0;
}