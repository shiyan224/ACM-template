#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int dfn[maxn], low[maxn], instack[maxn], _stack[maxn], cmp[maxn];
int _time, top, scc;
vector<int> G[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++_time;
    instack[u] = true;
    _stack[++top] = u;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scc++;
        int j;
        do {
            j = _stack[top--];
            cmp[j] = scc;
            instack[j] = false;
        } while (j != u);
    }
}
