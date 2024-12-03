// {2,7,61} for [1, 2^32)
int magic[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool witness(int a, int n, int u, int t) {
	if(!a) return false;
	int x = powm(a, u, n); // a, u using __int128 in `powm`
	for(int i = 0; i < t; i++) {
		int nx = (__int128)x * x % n;
		if(nx == 1 && x != 1 && x != n-1) return true;
		x = nx;
	}
	return x != 1;
}
bool miller_rabin(int n) {
	int s = 7;
	if(n < 2) return false;
	if(~n & 1) return n == 2;
	int u = n - 1, t = 0;
	while(~u & 1) u >>= 1, t++;
	while(s--) {
		int a = magic[s] % n;
		if(witness(a, n, u, t)) return false;
	}
	return true;
}
