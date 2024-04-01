#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N];
bool vis[N];
void dfs(int node)
{
    vis[node] = 1;
    for (int ch : g[node])
        if (!vis[ch])
            dfs(ch);
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
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
}

/*

*/