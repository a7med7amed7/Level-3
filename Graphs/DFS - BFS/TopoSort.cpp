#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N];
bool vis[N];
vector<int> v;
void dfs(int node)
{
    vis[node] = 1;
    for (int ch : g[node])
        if (!vis[ch])
            dfs(ch);
    v.push_back(node);
}
int main()
{
    // Acyclic (DAG)
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    reverse(v.begin(), v.end());
    for (auto e : v)
        cout << e << " ";
}

/*

*/