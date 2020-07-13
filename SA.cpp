int sa[maxn], c[maxn], t[maxn], t2[maxn];

void construct_sa(int n, int m)
{
    int *rk = t, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[rk[i] = C[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[rk[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[rk[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[rk[y[i]]]] = y[i];
        swap(rk, y);
        p = 1;
        rk[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            rk[sa[i]] = 
                y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] 
                    ? p - 1 
                    : p++;
        if (p >= n) break;
        m = p;
    }
}
