#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N];
bool vis[N];
int s = -1, e = -1;
int parent[N];
bool dfs(int node, int par)
{
    vis[node] = 1;
    parent[node] = par;
    for (int ch : g[node])
    {
        if (!vis[ch])
        {
            if (dfs(ch, node))
                return true;
        }
        else if (ch != par)
        {
            s = ch, e = node;
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0, mx = 0;
    cout << dfs(1, 0) << "\n";
    cout << s << " " << e << "\n";
    vector<int> path;
    while (e != s)
    {
        path.push_back(e);
        e = parent[e];
    }
    path.push_back(s);
    cout << path.size() << "\n";
    for (int p : path)
        cout << p << " ";
}

/*

*/