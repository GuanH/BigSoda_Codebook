// does not work when n is prime  O(n^(1/4))
int mul(__int128 a, __int128 b, int m) { return (a % m) * (b % m) % m; }
int pollard_rho(int p) {
  int x, y, z, c, g, i, j;
  while (1) { 
    y = x = rand() % p;  c = rand() % p;
    i = 0, z = j = 1; 
    while (++i) {
      x = (mul(x, x, p) + c) % p;  
      z = mul(z, abs(y - x), p); 
      if (x == y || !z) break;
      if (i % 127 == 0 || i == j) { 
        g = __gcd(z, p);
        if (g > 1) return g;
        if (i == j) y = x, j <<= 1;
} } } }