#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
int par[N], sz[N];
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
    /*
    if(rank[u] < rank[v])swap(u,v);
    par[v]=u;
    if(rank[u] == rank[v])
        rank[u]++;
    */
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
int main()
{
    int n, q;
    cin >> n >> q;
    init(n);
    for (int i = 0; i < q; i++)
    {
        // 1 u v => connect (u,v)
        // 2 u => findRoot(u)
        int op, u, v;
        cin >> op >> u;
        if (op == 1)
            cin >> v;
        if (op == 2)
            cout << sz[findRoot(u)] << "\n";
        else
            connect(u, v);
    }
}
/*
n=7,q=5
7 5
1 1 2
2 1
1 3 4
1 2 3
2 4
*/