#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N];
bool vis[N];
int timer = 1;
int ENTER[N], EXIT[N], dep[N];
void dfs(int node, int par)
{
    for (int ch : g[node])
    {
        if (ch == par)
            continue;
        dep[ch] = 1 + dep[node];
        dfs(ch, node);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << dep[i] << " ";
    }
}

/*
You are given N nodes and Q queries,
- u,v check u ancestor of v
*/