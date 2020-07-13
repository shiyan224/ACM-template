//n*m的矩阵中求子矩阵最大值
struct tree
{
    int st[maxn << 2];
    void build(int u, int L, int R, int p)
    {
        if (L == R) {
            st[u] = g[p][L];
            return;
        }
        int mid = L + R >> 1;
        build(lson, L, mid, p);
        build(rson, mid + 1, R, p);
        st[u] = max(st[lson], st[rson]);
    }
    int query(int u, int L, int R, int l, int r)
    {
        if (l <= L && R <= r) return st[u];
        int mid = L + R >> 1;
        int ret = 0;
        if (l <= mid) ret = max(ret, query(lson, L, mid, l, r));
        if (r > mid) ret = max(ret, query(rson, mid + 1, R, l, r));
        return ret; 
    }
} s[maxn << 2];

void pushup(int u, int uu, int L, int R)
{
    s[u].st[uu] = max(s[lson].st[uu], s[rson].st[uu]);
    if (L == R) return;
    int mid = L + R >> 1;
    pushup(u, uu*2, L, mid); pushup(u, uu*2+1, mid + 1, R);
}
int query(int u, int L, int R, int l1, int r1, int l2, int r2)
{
    if (l1 <= L && R <= r1) return s[u].query(1, 1, m, l2, r2);
    int mid = L + R >> 1;
    int ret = 0;
    if (l1 <= mid) ret = max(ret, query(lson, L, mid, l1, r1, l2, r2));
    if (r1 > mid) ret = max(ret, query(rson, mid+1, R, l1, r1, l2, r2));
    return ret;
}
void build(int u, int L, int R)
{
    if (L == R) {
        s[u].build(1, 1, m, L);
        return;
    }
    int mid = L + R >> 1;
    build(lson, L, mid); build(rson, mid + 1, R);
    pushup(u, 1, 1, m);
}