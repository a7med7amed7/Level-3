#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N];
bool vis[N];
int s = -1, e = -1;
int col[N], callStack[N];
bool dfs(int node)
{
    // Push stack
    vis[node] = 1;
    callStack[node] = 1;
    for (int ch : g[node])
    {
        if (!vis[ch])
        {
            if (dfs(ch))
                return true;
        }
        else
        {
            s = node, e = ch;
            if (callStack[ch])
                return true;
        }
    }
    // Pop stack
    callStack[node] = 0;
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
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
        }
    }
}

/*

*/