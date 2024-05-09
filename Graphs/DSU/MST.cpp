#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
int par[N], sz[N], mn[N];
void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i, sz[i] = 1;
}
int findRoot(int node)
{
    if (par[node] == node)
        return node;
    return par[node] = findRoot(par[node]);
}
void connect(int u, int v)
{
    u = findRoot(u);
    v = findRoot(v);
    if (u == v) // Same root {same set}
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
int main()
{
    int n, m;
    cin >> n >> m;
    init(n);
    vector<pair<int, pair<int, int>>> a(m); // {w,{u,v}};
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {w, {u, v}};
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int w = a[i].first, u = a[i].second.first, v = a[i].second.second;
        u = findRoot(u);
        v = findRoot(v);
        if (u == v)
            continue;
        ans = ans + 1LL * w;

        connect(u, v);
    }
    cout << ans << "\n";
}
