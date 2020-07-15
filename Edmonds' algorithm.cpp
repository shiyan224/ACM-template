//一般图匹配
bool g[N][N], inque[N], inpath[N];
bool inhua[N];
int st, ed, newbase, ans, n;
int base[N], pre[N], match[N];
int head, tail, que[N];
void Push(int u) {
    que[tail] = u;
    tail++;
    inque[u] = 1;
}
int Pop() {
    int res = que[head];
    head++;
    return res;
}
 
int lca(int u, int v) {
    memset(inpath, 0, sizeof(inpath));
    while (1) {
        u = base[u];
        inpath[u] = 1;
        if (u == st) break;
        u = pre[match[u]];
    }
    while (1) {
        v = base[v];
        if (inpath[v]) break;
        v = pre[match[v]];
    }
    return v;
}
void reset(int u) {
    int v;
    while (base[u] != newbase) {
        v = match[u];
        inhua[base[u]] = inhua[base[v]] = 1;
        u = pre[v];
        if (base[u] != newbase) pre[u] = v;
    }
}
void contract(int u, int v) {
    newbase = lca(u, v);
    memset(inhua, 0, sizeof(inhua));
    reset(u);
    reset(v);
    if (base[u] != newbase) pre[u] = v;
    if (base[v] != newbase) pre[v] = u;
    for (int i = 1; i <= n; i++) {
        if (inhua[base[i]]) {
            base[i] = newbase;
            if (!inque[i]) Push(i);
        }
    }
}
void findaug() {
    memset(inque, 0, sizeof(inque));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) base[i] = i;
    head = tail = 1;
    Push(st);
    ed = 0;
    while (head < tail) {
        int u = Pop();
        for (int v = 1; v <= n; v++) {
            if (g[u][v] && (base[u] != base[v]) && match[u] != v) {
                if (v == st || (match[v] > 0) && pre[match[v]] > 0)
                    contract(u, v);
                else if (pre[v] == 0) {
                    pre[v] = u;
                    if (match[v] > 0)
                        Push(match[v]);
                    else  //找到增广路
                    {
                        ed = v;
                        return;
                    }
                }
            }
        }
    }
}
void aug() {
    int u, v, w;
    u = ed;
    while (u > 0) {
        v = pre[u];
        w = match[v];
        match[v] = u;
        match[u] = v;
        u = w;
    }
}
void edmonds() {
    memset(match, 0, sizeof(match));
    for (int u = 1; u <= n; u++) {
        if (match[u] == 0) {
            st = u;
            findaug();
            if (ed > 0) aug();
        }
    }
}
