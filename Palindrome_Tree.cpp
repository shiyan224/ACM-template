
struct Palindromic_Tree {  
    //cnt最后count一下之后是那个节点代表的回文串出现的次数
    int next[MAXN][N] ;//next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成  
    int fail[MAXN] ;//fail指针，失配后跳转到fail指针指向的节点  
    int cnt[MAXN] ; //表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的） 
    int num[MAXN] ; //表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
    int len[MAXN] ;//len[i]表示节点i表示的回文串的长度（一个节点表示一个回文串）
    int S[MAXN] ;//存放添加的字符  
    int last ;//指向新添加一个字母后所形成的最长回文串表示的节点。
    int n ;//表示添加的字符个数。
    int p ;//表示添加的节点个数。

    int newnode (int l) {//新建节点  
        for ( int i = 0 ; i < N ; ++ i ) next[p][i] = 0 ;  
        cnt[p] = 0 ;  
        num[p] = 0 ;  
        len[p] = l ;  
        return p ++ ;  
    }  

    void init () {
        p = 0 ;  
        newnode (  0 ) ;  
        newnode ( -1 ) ;  
        last = 0 ;  
        n = 0 ;  
        S[n] = -1 ;
        fail[0] = 1 ;  
    }  

    int get_fail ( int x ) {
        while ( S[n - len[x] - 1] != S[n] ) x = fail[x] ;  
        return x ;  
    }  

    void add ( int c ) {  
        c -= 'a' ;  
        S[++ n] = c ;  
        int cur = get_fail ( last ) ;
        if ( !next[cur][c] ) {
            int now = newnode ( len[cur] + 2 ) ;  
            fail[now] = next[get_fail ( fail[cur] )][c] ;
            next[cur][c] = now ;  
            num[now] = num[fail[now]] + 1 ;  
        }  
        last = next[cur][c] ;  
        cnt[last] ++ ;  
    }  

    void count () {  
        for ( int i = p - 1 ; i >= 0 ; -- i ) cnt[fail[i]] += cnt[i] ;  
    }  
};
