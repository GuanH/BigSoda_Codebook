int discrete_sqrt(int y, int p) { // find x s.t. x^2 = y (mod p)
    if (!y) return 0;
    if (p == 2) return (y & 1) == 1 ? 1 : -1;
    if (fpow(y, p - 1 >> 1, p) != 1) return -1;
    int Q = p - 1, S = 0;
    while (~Q & 1) { Q >>= 1; S++; }
    if (S == 1) return fpow(y, p + 1 >> 2, p);
    int z;
    while (1) {
        z = 1 + rand() % (p - 1);
        if (fpow(z, p - 1 >> 1, p) != 1) break;
    }
    int c = fpow(z, Q, p), R = fpow(y, Q + 1 >> 1, p);
    int t = fpow(y, Q, p), M = S, b, i;
    while (1) {
        if (t % p == 1) break;
        for (i = 1; i < M && fpow(t, 1LL << i, p) != 1; i++);
        b = fpow(c, 1LL << M - i - 1, p);
        R = R * b % p;
        c = fpow(b, 2, p);
        t = t * c % p; M = i;
    }
    return (R % p + p) % p;
}