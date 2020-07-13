
int c[maxn], rk[maxn], y[maxn], sa[maxn];
//c——第一关键字出现的次数
//rk——rk[i]表示后缀i的排名,可重复
//y——按照第二关键字排序的后缀排名
//答案存在sa[0]-sa[n - 1]
void construct_sa(int n, int *r)
{
    int m = 10;
    for (int i = 0; i < n; i++)
        c[rk[i] = r[i]]++;
    for (int i = 1; i < m; i++)
        c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--)
        sa[--c[rk[i]]] = i;
    for (int k = 1; ; k <<= 1) {
        int p = 0;
        for (int i = n - k; i < n; i++) 
            y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) 
                y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++)     
            c[i] = 0;
        for (int i = 0; i < n; i++)
            c[rk[y[i]]]++;
        for (int i = 1; i < m; i++)
            c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--c[rk[y[i]]]] = y[i];
        swap(rk, y);
        rk[sa[0]] = 0;
        p = 1;
        for (int i = 1; i < n; i++)
            rk[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        m = p;
        if (p >= n) break;
    }
}
