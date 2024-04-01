#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N];
bool vis[N];
int s = -1, e = -1;
int col[N];
bool dfs(int node, int color)
{
    vis[node] = 1;
    for (int ch : g[node])
    {
        if (!vis[ch])
        {
            col[ch] = 1 - col[node];
            if (!dfs(ch, col[ch]))
                return false;
        }
        else
        {
            if (col[ch] == col[node])
                return false;
        }
    }
    return true;
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
    bool f = 1; // bipartite
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            col[i] = 0;
            f &= dfs(i, 0);
        }
    }
    cout << (f ? "TEUE" : "FALSE");
}

/*

*/