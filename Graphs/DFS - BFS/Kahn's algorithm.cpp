#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
vector<int> g[N], deg(N);
bool vis[N];
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
        deg[v]++;
        // g[v].push_back(u);
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(-i);
    }
    vector<int> v;
    while (!q.empty())
    {
        int node = -q.top();
        q.pop();
        v.push_back(node);
        for (int ch : g[node])
        {
            if (vis[ch])
                continue;
            deg[ch]--;
            if (deg[ch] == 0)
                q.push(-ch);
        }
    }
    for (int e : v)
        cout << (e) << " ";
}

/*
1 3 5 4 2
1 3 5 4 2
---------
1 3 2 4 5
*/