int BSGS(int start, int x, int y, int m) {
    unordered_map<int, int> mp;
    int big = 1, STEP = sqrt(m);
    for (int i = 0; i < STEP; i++) {
        mp[y] = i;
        y = y * x % m;
        big = big * x % m;
    }
    for (int step = 0; step < m + 10; step += STEP) {
        start = start * big % m;
        if (mp.count(start))
            return (step + STEP) - mp[start];
    }
    return -1;
}
int discrete_log(int x, int y, int m) { // find min k s.t. x^k = y (mod m)
    if (m == 1) return 0;
    int start = 1;
    for (int i = 0; i < 100; i++) {
        if (start == y) return i;
        start = start * x % m;
    }
    int pred = 100 + BSGS(start, x, y, m);
    if (fpow(x, pred, m) != y) return -1;
    return pred;
}