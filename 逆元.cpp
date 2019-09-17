LL extgcd(LL a, LL b, LL &x, LL & y) {
    LL d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
LL mod_inverse(LL a, LL m) {
    LL x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
