#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N];
bool vis[N];
int timer = 1;
int ENTER[N], EXIT[N];
void dfs(int node, int par)
{
    ENTER[node] = timer++;
    for (int ch : g[node])
    {
        if (ch == par)
            continue;
        dfs(ch, node);
    }
    EXIT[node] = timer++;
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
        cout << ENTER[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << EXIT[i] << " ";
    }
    cout << "\n";
}

/*
You are given N nodes and Q queries,
- u,v check u ancestor of v
*/