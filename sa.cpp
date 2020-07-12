int _rank[maxn], sa[maxn], lcp[maxn], y[maxn], c[maxn];

void construct_sa(int len)
{
    int m = 150;
    for (int i = 0; i < m; i++)
        c[i] = 0;
    for (int i = 0; i < len; i++)
        c[_rank[i] = s[i]]++;
    for (int i = 1; i < m; i++)
        c[i] += c[i-1];
    for (int i = len-1; i >= 0; i--) 
        sa[--c[s[i]]] = i;
    for (int k = 1; k <= len; k <<= 1) {
        int p = 0;
        for (int i = 0; i < m; i++)
            c[i] = 0;
        for (int i = len - k; i < len; i++)
            y[p++] = i;
        for (int i = 0; i < len; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < len; i++)
            c[_rank[y[i]]]++;
        for (int i = 1; i < m; i++)
            c[i] += c[i-1];
        for (int i = len - 1; i >= 0; i--) 
            sa[--c[_rank[y[i]]]] = y[i];
        p = 1; 
        swap(_rank, y);
        _rank[sa[0]] = 0;
        for (int i = 0; i < len; i++) 
            _rank[sa[i]] = _rank[sa[i-1]]==_rank[sa[i]] && _rank[sa[i-1]+k]==_rank[sa[i]+k] ? p-1 : p++;
        if (p >= len) break;
        m = p;
    }
}

void construct_lcp(int n)
{
    for (int i = 0; i <= n; i++)
        _rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[_rank[i] - 1];
        if (h > 0) h--;
        while (s[i+h] == s[j+h]) h++;
        lcp[_rank[i]] = h;
    }
}

// string str; 
// construct_sa(str.length() + 1);
