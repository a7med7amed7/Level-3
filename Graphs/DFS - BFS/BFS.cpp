#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int main()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<int> g[n + 1];
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // queue
    // push src node
    queue<int> q;
    vector<int> dist(n + 1);
    vector<bool> vis(n + 1, 0);
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int ch : g[node])
        {
            if (!vis[ch])
            {
                vis[ch] = 1;
                dist[ch] = 1 + dist[node];
                q.push(ch);
            }
        }
    }
    // Detect min cycle (V*E);
    // Floyd warshall
    // SSSP O(N*log(N))
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dist[i] << "\n";
    }
}

/*

*/